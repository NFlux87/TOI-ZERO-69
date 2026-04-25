#include <stdio.h>
void main(void)
{
        
    int width; scanf("%d", &width);
    int height; scanf("%d", &height);
    int nx; scanf("%d", &nx);
    int ny; scanf("%d", &ny);
    

    int kx[nx + 1];
    for(int i = 0;i < nx;i++)
    {  
        scanf("%d", &kx[i]); 
    }
    kx[nx] = width;


    int ky[ny + 1];
    for(int i = 0;i < ny; i++)
    {
        scanf("%d", &ky[i]);
    }
    ky[ny] = height;



    int high1 = 0;
    int high2 = 0;
    
    for(int i = 0;i < nx + 1; i++)
    {

        // Get Lastest X 
        int x = kx[i];
        if(i != 0)
        {
            x = kx[i] - kx[i - 1];
        }

        for(int j = 0; j < ny + 1; j++)
        {
            // Get Lastest Y
            int y = ky[j];
            if(j != 0)
            {
                y = ky[j] - ky[j - 1];
            }
            
            //Highest square
          
            int area = x * y;
            
            if(area > high1)
            {
                high2 = high1;
                high1 = area;
            }
            else if(area > high2)
            {
                high2 = area;
            }  
        }    
    }
    
    printf("%d %d", high1, high2);
}
