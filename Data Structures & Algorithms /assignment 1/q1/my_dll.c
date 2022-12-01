#include"my_dll.h"
#include"node.h"
#include<stdlib.h>
#include<stdio.h>

void insert(mystr list, int x)
{
    stptr temp;
    if(list->root != NULL)
    {
        temp = malloc(sizeof(struct node));
        stptr t2 = list->tail;
        temp->a = x;
        temp->prev = t2;
        t2->next = temp;
        list->tail = temp;
        list->size = list->size + 1;
    }
    if(list->root == NULL)
    {
        list->size = 0;
        temp = (stptr)malloc(sizeof(struct node));
        temp->a = x;
        temp->next = NULL;
        temp->prev = NULL;
        list->root = temp;
        list->tail = temp;
    }
}
int insert_at(mystr list, int x, int i)
{
    if(i == list->size || list->size < 0)
    {
        insert(list, x);
        return 0;
    } 
    if (i == 0)
    {
        stptr t3, temp = malloc(sizeof(struct node));
        temp->a = x;
        list->size = list->size + 1;
        temp->next = list->root;
        list->root->prev = temp;
        list->root = temp;
        temp->prev = NULL;
        return 0;
    }
    stptr t2 = list->root;
    for (int j = 0; j < i - 1; j++)
    {
        t2 = t2->next;
    }
    stptr t3, temp = malloc(sizeof(struct node));
    temp->a = x;
    t2->next = t3;
    t2->next = temp;
    temp->prev = t2;
    temp->next = t3;
    if(i > list->size) list->tail = temp;
    list->size = list->size + 1;
    return 0;
}

int Delete(mystr list, int i)
{
    if(i == 0)
    {
        if(list->size <= 0)
        {
            free(list->root);
            list->root = NULL; 
            return 0;
        }
        list->size = list->size - 1;
        stptr t = list->root;
        list->root = list->root->next;
        free(t); 
        return 0;
    }
    if(i == list->size)
    {
        list->size = list->size - 1;
        stptr t = list->tail->prev;
        free(list->tail);
        list->tail = t;
        t->next = NULL;
        return 0;
    }
    list->size = list->size - 1;
    stptr t1, t2, t = list->root;
    for (int j = 0; j < i; j++)
    {
        t = t->next;
    }
    t2 = t->next;    /// t1 t t2
    t1 = t->prev;
    t1->next = t2;
    t2->prev = t1;
    free(t);
    return 0;
}

int find(mystr list, int x)
{
    stptr t1, t2, t = list->root;
    for (int j = 0; j <= list->size; j++)
    {
        if(t->a == x) return j;
        t = t->next;
    }
    return -1;
}

void prune(mystr list)
{
    // int c = 0;
    // stptr t1, t2, t = list->root;
    // for (int j = 0; j <= list->size; j++)
    // {
    //     if(c%2 == 1) Delete(list, j);
    //     t = t->next;
    //     c++;
    // }
    // 1 2 3 4 5 6 7 8 9 
    for (int j = 1; j <= list->size; j++)
    {
        Delete(list, j);
    }
    
}

void print(mystr list)
{
    stptr t1, t2, t = list->root;
    for (int j = 0; j <= list->size; j++)
    {
        int c = t->a;
        printf("%d ", c);
        t = t->next;
    }
    printf("\n");
}

void print_reverse(mystr list)
{
    stptr t1, t2, t = list->tail;
    for (int j = 0; j <= list->size; j++)
    {
        int c = t->a;
        printf("%d ", c);
        t = t->prev;
    }
    printf("\n");
}

void get_size(mystr list)
{
    printf("%d \n", list->size + 1);
}