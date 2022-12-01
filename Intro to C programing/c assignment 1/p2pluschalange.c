#include <stdio.h>
int main() {    

    int n1, n2, sum, i, x, y, z;
    i = 1;
    printf("Enterninteger: ");
    scanf("%d %d", &n1, &n2);
   
     while (i < n2 + 1) { 
        printf("%d ", n1*i);
        i = i + 1;

        }

   
    return 0;
}
