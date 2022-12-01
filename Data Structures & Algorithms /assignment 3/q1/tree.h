#ifndef TREE_H
#define TREE_H
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#define ll long long int 
struct tree
{
    struct tree * l;
    struct tree * r;
    ll a;
    ll min;
    ll max;
    int ascending;
    int desending;
    ll sum;
};
typedef struct tree* treenode;

void freetree(treenode t);
treenode makenode(ll a);
void printpreorder(treenode t);
void minmax(treenode t);
void printpreorderminmax(treenode t);
void left(treenode t);
void right(treenode t);
#endif