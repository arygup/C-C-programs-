#include"complex.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
double* add(cst a, cst b)
{
    double* temp = malloc(__SIZEOF_DOUBLE__*a->n);
    for (int i = 0; i < a->n; i++)
    {
        temp[i] = a->coeff[i] + b->coeff[i];
    }
    return temp;
}

double* sub(cst a, cst b)
{
    double* temp = malloc(__SIZEOF_DOUBLE__*a->n);
    for (int i = 0; i < a->n; i++)
    {
        temp[i] = a->coeff[i] - b->coeff[i];
    }
    return temp;
}

double mod(cst a)
{
    double s = 0;
    for (int i = 0; i < a->n; i++)
    {
        s = s + a->coeff[i]*a->coeff[i];
    }
    return sqrt(s);
}

double dot(cst a, cst b)
{
    double s = 0;
    for (int i = 0; i < a->n; i++)
    {
        s =  s + (a->coeff[i] * b->coeff[i]);
    }
    return s;
} 

double cosi(cst a, cst b)
{
    return (dot(a, b)/( mod(a)*mod(b)));
}
