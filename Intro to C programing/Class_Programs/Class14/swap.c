#include <stdio.h>

int swap (int *A, int *B)
{
    int temp;

    temp = *A;
    *A = *B;
    *B = temp;

}


int main ()
{
    int vara = 10, varb = 20;


    printf("before swapping: %d %d\n", vara, varb);
    swap(&vara, &varb);

    printf("after swapping: %d %d\n", vara, varb); 

}