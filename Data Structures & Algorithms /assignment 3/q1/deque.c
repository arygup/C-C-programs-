#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#include"deque.h"
#define ll long long int 
treenode popf(DQ dq)
{
    if(dq->head == NULL) return NULL;
    treenode x = dq->head->a;
    dq->head = dq->head->next;
    if(dq->head != NULL)dq->head->prev = NULL;
    dq->size--;
    return x;
}
treenode popb(DQ dq)
{
    if(dq->tail == NULL) return NULL;
    treenode x = dq->tail->a;
    dq->tail = dq->tail->prev;
    if(dq->tail != NULL)dq->tail->next = NULL;
    dq->size--;
    return x;
}
void pushb(DQ dq, treenode x)
{
    node temp;
    if(dq->head != NULL)
    {
        temp = malloc(sizeof(struct nodes));
        node t2 = dq->tail;
        temp->next = NULL;
        temp->a = x;
        temp->prev = t2;
        t2->next = temp;
        dq->tail = temp;
        dq->size = dq->size + 1;
    }
    if(dq->head == NULL)
    {
        dq->size = 1;
        temp = malloc(sizeof(struct nodes));
        temp->a = x;
        temp->next = NULL;
        temp->prev = NULL;
        dq->head = temp;
        dq->tail = temp;
    }
}
void pushf(DQ dq, treenode x)
{
    node temp;
    if(dq->head != NULL)
    {
        temp = malloc(sizeof(struct nodes));
        node t2 = dq->head;
        temp->a = x;
        temp->next = t2;
        temp->prev = NULL;
        t2->prev = temp;
        dq->head = temp;
        dq->size = dq->size + 1;
    }
    if(dq->head == NULL)
    {
        dq->size = 1;
        temp = malloc(sizeof(struct nodes));
        temp->a = x;
        temp->next = NULL;
        temp->prev = NULL;
        dq->head = temp;
        dq->tail = temp;
    }
}
treenode front(DQ dq)
{
    if(dq->head == NULL) return NULL;
    return dq->head->a;
}
treenode back(DQ dq)
{
    if(dq->tail == NULL) return NULL;
    return dq->tail->a;
}
ll size(DQ dq)
{
    return dq->size;
}
int isEmpty(DQ dq)
{
    if(dq->size == 0) return 1;
    return 0;
}

DQ makeDQ()
{
    DQ dq = malloc(sizeof(struct my));
    dq->head = NULL;
    dq->tail = NULL;
    dq->size = 0;
    return dq;
}
