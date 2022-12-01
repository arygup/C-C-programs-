#ifndef DEQUE_H
#define DEQUE_H
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#include"tree.h"
#define ll long long int 

struct nodes
{
    struct nodes * next;
    struct nodes * prev;
    treenode a;
};
typedef struct nodes* node;

struct my
{
    node head;
    node tail;
    ll size;
};
typedef struct my* DQ;

DQ makeDQ();
treenode popf(DQ dq);
treenode popb(DQ dq);
void pushb(DQ dq, treenode x);
void pushf(DQ dq, treenode x);
treenode front(DQ dq);
treenode back(DQ dq);
ll size(DQ dq);
int isEmpty(DQ dq);
void freeDQ(DQ dq);
void recfreeDQ(node nd);
#endif