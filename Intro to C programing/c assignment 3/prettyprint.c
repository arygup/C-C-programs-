#include <stdio.h>
int main()
{
    int a, d;
    d = -1;
    scanf("%d", &a);
    int B[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &B[i]);
        if (B[i] != 0)
        {
            d = i;
        }
    }
    if (d==-1)
    {
        printf("0");
        return 0;
    }
    if (d == 1)
    {
        goto ez;
    }
    if (d == 0)
    {
        goto pz;
    }
    if (B[d] == 1)
    {
        printf("x^%d ", d);
    }
    if (B[d] == -1)
    {
        printf("- x^%d ", d);
    }
    if ( (B[d] > 0 && B[d] != 1) ||  (B[d] < 0 && B[d] != -1) )
    {
        printf("%dx^%d ", B[d], d);
    }
    for (int i = d - 1; i > 1; i--)
    {
        if (B[i] == 1)
        {
            printf("+ x^%i ", i);
        }
        if (B[i] == -1)
        {
            printf("- x^%i ", i);
        }
        if (B[i] > 0 && B[i] != 1)
        {
            printf("+ %dx^%i ", B[i], i);
        }
        if (B[i] < 0 && B[i]!= -1)
        {
            printf("- %dx^%i ", -B[i], i);
        }
    }
    if (B[1] > 0)
    {
        if (B[1] != 1)
        {
            printf("+ %dx ", B[1]);
        }
        if (B[1] == 1)
        {
            printf("+ x ");
        }
    }
    if (B[1] < 0)
    {
        if (B[1] != -1)
        {
            printf("- %dx ", -B[1]);
        }
        if (B[1] == -1)
        {
            printf("- x ");
        }
    }
    if (B[0] > 0)
    {
        printf("+ %d", B[0]);
    }
    if (B[0] < 0)
    {
        printf("- %d", -B[0]);
    }
    return 0;
ez:
    if (B[1] > 0)
    {
        if (B[1] != 1)
        {
            printf("%dx ", B[1]);
        }
        if (B[1] == 1)
        {
            printf("x ");
        }
    }
    if (B[1] < 0)
    {
        if (B[1] != -1)
        {
            printf("%dx ", B[1]);
        }
        if (B[1] == -1)
        {
            printf("- x ");
        }
    }
    if (B[0] > 0)
    {
        printf("+ %d", B[0]);
    }
    if (B[0] < 0)
    {
        printf("- %d", -B[0]);
    }
    return 0;
pz:
    printf("%d", B[0]);
    return 0;
}