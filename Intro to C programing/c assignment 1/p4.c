#include <stdio.h>
#include <math.h>

int main () 
{
     int n1, n2; 
     printf(" enterintegers:");
    scanf("%d %d", &n1, &n2);

     
    for (int i = 2; i <= n1; i++) 
    {
        if (n1 % i == 0) 
        {

            if(n2 % i == 0)
            {
                printf("not coprimes\n");
               return 0;
            }

          
        }

    printf("coprimes.\n");
        return 0;
    }


    return 0;
} 
