#include <stdio.h>

int main()
{
    int a, abs_a; 
    printf ("Enter a value: ");
    scanf ("%d", &a);


    if (a>= 0)
    {
        abs_a = a;
    }
    else
    {
        abs_a = -a;
    }

    printf ("|%d| = %d\n", a, abs_a);
}