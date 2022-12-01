#include <stdio.h>
#include <math.h>
int main(void) {    
    long long n1, x, y, z, i;
    scanf("%lld", &n1);
    i = 0;
    z = 5;
    x = 2;
    y = 4;
    while (i < n1){
        while (y<201){
            while(z<201) {         
                if (x*x + y*y == z*z) {
                   printf("%1lld %1lld %1lld \n", x,y,z);
                   i = i + 1;        
                }
                z++;         
            }
            y++;
            z=y+1;
        }
        x++;
        y=x+1;
        z=x+2;
    }

}
