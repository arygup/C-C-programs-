#ifndef COMPLEX_H
#define COMPLEX_H
#include<stdlib.h>

struct complex
{
    double* coeff;
    int n;
};

typedef struct complex* cst;


double* add(cst a, cst b);
double* sub(cst a, cst b); 
double mod(cst a); 
double dot(cst a, cst b); 
double cosi(cst a, cst b); 
#endif
