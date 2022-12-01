#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#include"tree.h"
#define ll long long int 

void freetree(treenode t)
{
    if(t == NULL) return;
    treenode l = t->l, r = t->r;
    free(t);
    freetree(l);
    freetree(r);
}

treenode makenode(ll a)
{
    treenode t = malloc(sizeof(struct tree));
    t->a = a;
    t->l = NULL;
    t->r = NULL;
    t->max = a;
    t->min = a;
    t->ascending = 0;
    t->desending = 0;
    return t;
}

void printpreorder(treenode t)
{
    if(t == NULL) return;
    printf("%lld  ", t->a);
    printpreorder(t->l);
    printpreorder(t->r);
}

void minmax(treenode t)
{
    if(t == NULL) return;
    minmax(t->l);
    minmax(t->r);
    if(t->l != NULL) if(t->l->min < t->min) t->min = t->l->min;
    if(t->r != NULL)if(t->r->min < t->min) t->min = t->r->min;
    if(t->l != NULL)if(t->l->max > t->max) t->max = t->l->max;
    if(t->r != NULL)if(t->r->max > t->max) t->max = t->r->max;
}

void printpreorderminmax(treenode t)
{
    if(t == NULL) return;
    printf("%lld %lld %lld     ",t->a, t->max, t->min);
    printpreorderminmax(t->l);
    printpreorderminmax(t->r);
}

void left(treenode t)
{
    if(t->l == NULL && t->r == NULL)
    {
        t->ascending = 1;
        return;
    }
    ll a = 1, b = 1, L = -__LONG_LONG_MAX__, R = __LONG_LONG_MAX__;
    if(t->l != NULL)
    {
        left(t->l);
        a = t->l->ascending;
    }
    if(t->r != NULL)
    {
        left(t->r);
        b = t->r->ascending;
    }
    if(t->l != NULL) L = t->l->max;
    if(t->r != NULL) R = t->r->min;
    if((L < t->a && R > t->a) && a && b) t->ascending = 1;
}

void right(treenode t)
{
    if(t->l == NULL && t->r == NULL)
    {
        t->desending = 1;
        return;
    }
    ll a = 1, b = 1, L = __LONG_LONG_MAX__, R = -__LONG_LONG_MAX__;
    if(t->l != NULL)
    {
        right(t->l);
        a = t->l->desending;
    }
    if(t->r != NULL)
    {
        right(t->r);
        b = t->r->desending;
    }
    if(t->l != NULL) L = t->l->min;
    if(t->r != NULL) R = t->r->max;
    if((L > t->a && R < t->a) && a && b) t->desending = 1;
}