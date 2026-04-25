#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
// This File I use Ai For help Because it so Hard for me

#define MAXPTS 500*500+1
double pts[MAXPTS];
int npts = 0;

typedef struct
{
    int x1; int y1;
    int x2; int y2; 
} Sagement;


Sagement* getSagement(int size, int x[]);
void freeSagement(Sagement* seg);
int getCrossCount(Sagement* r, Sagement* b, int N, int M); 


void main()
{
    
    int N; scanf("%d", &N);
    int M; scanf("%d", &M);
    
    int redx[N + 1];
    redx[0] = 0;
 
    int bluex[M + 1];
    bluex[0] = 0;
    

    // RedX
    for(int i = 1; i <= N; i++)
    {
        scanf("%d", &redx[i]);
    }
    
    // BlueX
    for(int i = 1; i <= M; i++)
    {
        scanf("%d", &bluex[i]);
    }
    
    // Create Sagement of Layser
    Sagement* red_sagement = getSagement(N, redx);
    Sagement* blue_sagement = getSagement(M, bluex);
    
    
// TEST---------------------------------------
/*    printf("Red Sagement\n");
    for(int i = 0; i < N ;i ++)
    {
        printf("rx1 : %d ry1 : %d\n", red_sagement[i].x1, red_sagement[i].y1);
        printf("rx2 : %d ry2 : %d\n", red_sagement[i].x2, red_sagement[i].y2);
    }

    printf("Blue Sagement\n");
    for(int i = 0; i < M; i++)
    {
        printf("bx1 : %d by1 : %d\n", blue_sagement[i].x1, blue_sagement[i].y1);
        printf("bx1 : %d by1 : %d\n", blue_sagement[i].x2, blue_sagement[i].y2);
    }
 */   
    
// TEST-------------------------------------
 

    
    int crossCount = getCrossCount(red_sagement, blue_sagement, N, M);
    
    printf("%d", crossCount);

    freeSagement(red_sagement);
    freeSagement(blue_sagement);

    

}

Sagement* getSagement(int size, int x[])
{
    
    Sagement* sagements = (Sagement*)malloc(size * sizeof(Sagement));

    // Set Value of Sagements
    for(int i = 0; i < size; i++)
    {
        // Check for set value Y
        if(i % 2 == 0)
        {

            sagements[i].x1 = x[i];
            sagements[i].y1 = 0;

            sagements[i].x2 = x[i + 1];
            sagements[i].y2 = 1;
    
        }
        else
        {
            sagements[i].x1 = x[i];
            sagements[i].y1 = 1;
                
            sagements[i].x2 = x[i + 1];
            sagements[i].y2 = 0;
        }
    }

    return sagements;

}

void freeSagement(Sagement* seg)
{
    if(seg != NULL)
    {
        free(seg);
    }
}

bool almostEqual(double a, double b) { return fabs(a-b) < 1e-6; }
void addPt(double x) {

    for(int i = 0; i < npts; i++)
    { 
        if(almostEqual(pts[i], x)) return;
    }
    pts[npts++] = x;
}

int getCrossCount(Sagement* r, Sagement* b, int N, int M) {
    // Add 0
    addPt(0.0);

    double eps = 1e-9;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            
            double x1=r[i].x1, y1=r[i].y1, x2=r[i].x2, y2=r[i].y2;
            double x3=b[j].x1, y3=b[j].y1, x4=b[j].x2, y4=b[j].y2;
            
            double D = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);
            
            if(fabs(D) < eps) continue;
            double alpha = ((x1-x3)*(y3-y4) - (y1-y3)*(x3-x4)) / D;
            double beta  = ((x1-x3)*(y1-y2) - (y1-y3)*(x1-x2)) / D;
            
            if(alpha >= -eps && alpha <= 1+eps && beta >= -eps && beta <= 1+eps) {
                double ix = x1 + alpha*(x2-x1);
                addPt(ix);
            }
        }
    }
    return npts;
}
