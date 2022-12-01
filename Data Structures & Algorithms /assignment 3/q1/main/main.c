#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<assert.h>
#define ll long long int 

ll A = __LONG_LONG_MAX__;


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

void rootchecker(treenode t)
{
    ll a = 1, b = 1, L = -__LONG_LONG_MAX__, R = __LONG_LONG_MAX__;
    if(t->l != NULL)
    {
        a = t->l->ascending;
    }
    if(t->r != NULL)
    {
        b = t->r->ascending;
    }
    if(t->l != NULL) L = t->l->max;
    if(t->r != NULL) R = t->r->min;
    if((L < t->a && R > t->a) && a && b) t->ascending = 1;
    if(t->l != NULL)
    {
        a = t->l->desending;
    }
    if(t->r != NULL)
    {
        b = t->r->desending;
    }
    if(t->l != NULL) L = t->l->min;
    if(t->r != NULL) R = t->r->max;
    if((L > t->a && R < t->a) && a && b) t->desending = 1;
}

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
    printf("%lld %d %d     ",t->a, t->ascending, t->desending);
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

void solve(treenode t)
{
    if (t == NULL) return;
    solve(t->l);
    solve(t->r);
    int L = 0, R = 0;
    if (t->l == NULL && t->r == NULL) t->sum = t->a;
    if (t->l != NULL) L = t->l->sum;
    if (t->r != NULL) R = t->r->sum;
    t->sum = t->a + L + R;
    if (t->sum < A && (t->desending || t->ascending))A = t->sum;
}

int main()
{
    ll n, count, el1, el2;
    scanf("%lld", &count);
    for (ll k = 0; k < count; k++)
    {
        scanf("%lld", &n);
        if (n == 0)
        {
            printf("\n");
            continue;
        }
        else if (n == 1)
        {
            scanf("%lld", &el1);
            if(el1 != 0)printf("%lld\n", el1);
            continue;
        }
        DQ dq = makeDQ();
        treenode t1, T;
        scanf("%lld", &el1);
        treenode root = makenode(el1);
        pushf(dq, root);
        for (ll i = 1; i < n; i++)
        {
            scanf("%lld", &el1);
            t1 = NULL;
            if(el1 != 0)
            {
                t1 = makenode(el1);
                pushb(dq, t1);
            } 
            if(i%2 == 1)
            {
                T = front(dq);
                T->l = t1;
            }
            if(i%2 == 0)
            {
                T = popf(dq);
                T->r = t1;
            } 
        }
        minmax(root);
        left(root);
        right(root);
        //rootchecker(root);
        solve(root);
        printf("%lld\n", A);
        //printpreorder(root);
        //printf("\n");
        //printpreorderminmax(root);
        //printf("%lld %lld %lld", root->a, root->max, root->min);
        free(dq);
        A = __LONG_LONG_MAX__;
        freetree(root);
    }
}