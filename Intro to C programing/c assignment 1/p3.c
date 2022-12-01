#include <stdio.h>
#include <math.h>
int main() {
    int number, i;
    float x, y, z;

    printf("Enter an integer: ");
    scanf("%d", &number);
    x = 0;
    i = 1;
    while (i < number + 1) {
        y = sqrt(i);
        x = x + y;
        i = i + 1; 

    }
    printf("%f", x );

    
    

return 0;
}