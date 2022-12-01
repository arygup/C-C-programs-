#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<assert.h>
#include"tree.h"
#include"deque.h"
#define ll long long int 
ll A = __LONG_LONG_MAX__;
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