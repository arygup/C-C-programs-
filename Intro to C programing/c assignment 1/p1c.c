#include <stdio.h>
#include <math.h>
//gc.cc p1c -o p1c
//the reason for x=0 and y=0 was found through gdb, warna 345>456>567 aise chal raha tha code
int main() {    

    int n1, n2, sum, x, y, z, i;
    
    printf("Enter integer: ");
    scanf("%d ", &n1);
    i = 0;
    z = 5;
    x = 2;
    y = 4;
    while (i < n1){

        while (y<z){
             
            while(x<y) {
                
                if (x*x + y*y == z*z) {

                 printf("%d %d %d \n", x,y,z);

                 i = i + 1;
                }
                x++;
            
            }
            y++;
            x=0;

        }
        z++;
        y=2;
        x=0;

    }

    
}
