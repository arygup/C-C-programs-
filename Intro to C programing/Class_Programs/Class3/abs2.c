#include <stdio.h>

void main(void)
{
    int a; 
    printf ("Enter a value: ");
    scanf ("%d", &a);


    if (a>= 0)
    {
       printf ("|%d| = %d\n", a, a);
    }
    else
    {
        printf ("|%d| = %d\n", a, -a);
    }

}