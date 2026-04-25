#include <stdio.h>


void main(void){
        
    int n;
    scanf("%d", &n);
    
    int h[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &h[i]);
    }

    int count = 0;
    
    int lenght = sizeof(h) / sizeof(h[0]);

    for(int i = 0; i < n; i++)
    {
        if(i == 0){
            if (h[i] > h[i + 1]) count ++;
        }
        else if (i == n - 1){
            if (h[i] > h[i - 1]) count ++;
        }
        else{
            if (h[i - 1] < h[i] && h[i] > h[i + 1]) count ++;
        }
    }

    printf("%d", count);

    

}
