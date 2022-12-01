#ifndef _node_H
#define _node_H
#include<stdlib.h>

struct node
{
    struct node * next;
    struct node * prev;
    int a;
};

typedef struct node* stptr ;

#endif