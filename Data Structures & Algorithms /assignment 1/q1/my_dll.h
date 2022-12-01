#ifndef _MY_DLL_H
#define _MY_DLL_H
#include"node.h"
#include<stdlib.h>

struct my_dll
{
    stptr root;
    stptr tail;
    int size;
};

typedef struct my_dll* mystr;


void insert(mystr list, int x);
int insert_at(mystr list, int x, int i); //
int Delete(mystr list, int i);
int find(mystr list, int x);
void prune(mystr list);
void print(mystr list);
void print_reverse(mystr list);
void get_size(mystr list);


#endif