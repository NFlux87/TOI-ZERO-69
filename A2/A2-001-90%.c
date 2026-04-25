#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct
{
    int x1; int y1;
    int x2; int y2; 
} Sagement;


Sagement* getSagement(int size, int x[]);
void freeSagement(Sagement* seg);
bool isCrossSagement(int red_x1, int red_y1, int red_x2, int red_y2,
                    int blue_x1, int blue_y1, int blue_x2, int blue_y2);
int getCrossCount(Sagement* seg_red, Sagement* seg_blue, int size_red, int size_blue);


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

int getCrossCount(Sagement* seg_red, Sagement* seg_blue, int size_red, int size_blue)
{
    // This function Return How many cross are There
    int count = 0;
    

    // Check Every How many Line is Cross
    for(int i = 0;i < size_red; i++)
    {
        for(int j = 0; j < size_blue; j++)
        {
            if (isCrossSagement(
                        seg_red[i].x1, seg_red[i].y1,   // A
                        seg_red[i].x2, seg_red[i].y2,   // B
                        seg_blue[j].x1, seg_blue[j].y1, // C
                        seg_blue[j].x2, seg_blue[j].y2  // D
                        ))
            {
                count++;
            }
        }
    }

    return count;
}

bool isCrossSagement(int red_x1, int red_y1, int red_x2, int red_y2,
                    int blue_x1, int blue_y1, int blue_x2, int blue_y2)
{
    
    // red_X1 and red_y1    = A 
    // red_x2 and red_y2    = B
    // blue_x1 and blue_y1  = C
    // blue_x2 and blue_y2  = D
    
    double x1 = (double)red_x1; // x1
    double y1 = (double)red_y1; // y1
    double x2 = (double)red_x2; // x2
    double y2 = (double)red_y2; // y2

    
    double x3 = (double)blue_x1; // x3
    double y3 = (double)blue_y1; // y3
    double x4 = (double)blue_x2; // x4
    double y4 = (double)blue_y2; // y4
    
            //(x1 - x2)(y3 - y4) - (y1 - y2)(x3 - x4)
    double D = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
    
    if(fabs(D) < 1e-10){
        return false;
    }

    // Calculate Alpha and Beta
    double alpha = ((x1 - x3) * (y3 - y4) - (y1- y3) * (x3 - x4)) / D;
    double beta = ((x1 - x3) * (y1 - y2) - (y1 - y3) * (x1 - x2)) / D;
    
    if(alpha >= 0.0 && alpha < 1.0 && beta >= 0.0 && beta < 1.0)
    {
        return true;
    }
    
    return false;
}

