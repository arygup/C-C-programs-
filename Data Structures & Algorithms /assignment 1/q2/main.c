#include"complex.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
    char f[100];
    scanf("%s", f);
    int n;
    scanf("%d", &n);
    //printf("%d\n", n);
    char f1[30] = "ADD";
    char f2[30] = "SUB";
    char f6[30] = "SUBTRACT";
    char f3[30] = "MOD";
    char f4[30] = "DOT";
    char f5[30] = "COS";
    char f7[30] = "COSINE";
    cst a = malloc(sizeof(struct complex));
    cst b = malloc(sizeof(struct complex));
    a->coeff = malloc(__SIZEOF_DOUBLE__*n);
    b->coeff = malloc(__SIZEOF_DOUBLE__*n);
    a->n = n;
    b->n = n;
    if(strcasecmp(f1, f) == 0)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &a->coeff[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &b->coeff[i]);
        }
        printf("\n");
        double *c = add(a, b);
        for (int i = 0; i < n; i++)
        {
            printf("%.2lf ", c[i]);
        }
        printf("\n");
    }
    if(strcasecmp(f2, f) == 0 || strcasecmp(f6, f) == 0)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &a->coeff[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &b->coeff[i]);
        }
        double *c = sub(a, b);
        for (int i = 0; i < n; i++)
        {
            printf("%.2lf ", c[i]);
        }
    }
    if(strcasecmp(f3, f) == 0)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &a->coeff[i]);
        }
        // for (int i = 0; i < n; i++)
        // {
        //     printf("%.2lf ", a->coeff[i]);
        // }
        // printf("\n");
        double c = mod(a);
        printf("%.2lf ", c);
    }
    if(strcasecmp(f4, f) == 0)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &a->coeff[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &b->coeff[i]);
        }
        double c = dot(a, b);
        printf("%.2lf ", c);
        
    }
    if(strcasecmp(f5, f) == 0 || strcasecmp(f7, f) == 0)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &a->coeff[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &b->coeff[i]);
        }
        double c = cosi(a, b);
        printf("%.2lf ", c);
    }
    return 0;
}
