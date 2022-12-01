#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#define ll long long int 
struct stacks{
    ll top;
    ll* array;
    ll n;
};
typedef struct stacks* stack;
ll gcd(ll x, ll y)
{
    ll a = 0;
    if(x==0)
    {
        return y;
    }
    a = gcd(y%x, x);
    return a;
}
ll lcm(ll x, ll y)
{
    return (x*y)/gcd(x, y);
}
ll pop(stack s)
{
    if(s->top <= -1) return -1;
    s->top = s->top - 1;
    return s->array[s->top+1];
}
ll push(stack s, ll a)
{
    if(s->top >= s->n-1) return -1;
    s->top = s->top + 1;
    s->array[s->top] = a;
    return 1;
}
ll top(stack s)
{
    return s->array[s->top];
}
int isEmpty(stack s)
{
    if(s->top <= -1) return 1;
    return 0;
}
ll size(stack s)
{
    return s->top+1;
}
void reset(stack s)
{
    s->top = -1;
}
ll max;
void histmax(stack s, ll m, ll A[m])
{
    reset(s);   // 1 2 3 4 3 2 1 0 5 3 7 1 
    ll i = 0;
    while (i < m)
    {
        if(size(s) == 0)
        {
            push(s, i);
            i++;
            continue;
        }
        if(A[i] >= A[top(s)])
        {
            push(s, i);
            i++;
            continue;
        }
        if(A[i] < A[top(s)])
        {
            ll t = A[pop(s)];
            ll maxwidth;
            if(isEmpty(s) == 1) maxwidth = i;
            else maxwidth = i - top(s) - 1;
            t = t*maxwidth;
            if(t > max) max = t;
        }
    }
    while (isEmpty(s) != 1)
    {
        ll t = A[pop(s)];
        ll maxwidth;
        if(isEmpty(s) == 1) maxwidth = i;
        else maxwidth = i - top(s) - 1;
        t = t*maxwidth;
        if(t > max) max = t;
    }
}
int main()
{
    max = 0;
    stack s = malloc(sizeof(struct stacks));
    assert(s != NULL);
    ll n, m;
    scanf("%lld %lld", &n, &m);
    s->n = m;
    s->array = malloc(__SIZEOF_LONG_LONG__*m);
    s->top = -1;
    ll A[m], x;
    for (ll i = 0; i < m; i++)
    {
        A[i] = 0;
    }
    char c;
    scanf("%c", &c);
    for (ll j = 0; j < n; j++)
    {
        for (ll i = 0; i < m; i++)
        {
            x = 0;
            scanf("%c", &c);
            if(c == 46) x = 1;
            A[i] = (A[i]*x) + x;
            //printf("%lld ", A[i]);
        }
        scanf("%c", &c);
        histmax(s, m, A);
        //printf("\n");
    }
    printf("%lld", max);
}

