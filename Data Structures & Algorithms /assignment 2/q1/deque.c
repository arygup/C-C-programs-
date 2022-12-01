#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#define ll long long int 
struct nodes
{
    struct nodes * next;
    struct nodes * prev;
    ll a;
};
typedef struct nodes* node;
struct my
{
    node head;
    node tail;
    ll size;
};
typedef struct my* DQ;
ll popf(DQ dq)
{
    if(dq->head == NULL) return -1;
    ll x = dq->head->a;
    dq->head = dq->head->next;
    if(dq->head != NULL)dq->head->prev = NULL;
    dq->size--;
    return x;
}
ll popb(DQ dq)
{
    if(dq->tail == NULL) return -1;
    ll x = dq->tail->a;
    dq->tail = dq->tail->prev;
    if(dq->tail != NULL)dq->tail->next = NULL;
    dq->size--;
    return x;
}
void pushb(DQ dq, ll x)
{
    node temp;
    if(dq->head != NULL)
    {
        temp = malloc(sizeof(struct nodes));
        node t2 = dq->tail;
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
void pushf(DQ dq, ll x)
{
    node temp;
    if(dq->head != NULL)
    {
        temp = malloc(sizeof(struct nodes));
        node t2 = dq->head;
        temp->a = x;
        temp->next = t2;
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
ll front(DQ dq)
{
    if(dq->head == NULL) return -1;
    return dq->head->a;
}
ll back(DQ dq)
{
    if(dq->tail == NULL) return -1;
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

int main()
{
    
}