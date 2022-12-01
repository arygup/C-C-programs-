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
int main()
{
    ll n;
    scanf("%lld", &n);
    stack s = malloc(sizeof(struct stacks));
    assert(s != NULL);
    s->n = n;
    s->array = malloc(__SIZEOF_LONG_LONG__*n);
    s->top = -1;
    stack s1 = malloc(sizeof(struct stacks));
    assert(s1 != NULL);
    s1->n = n;
    s1->array = malloc(__SIZEOF_LONG_LONG__*n);
    s1->top = -1;
    ll h[n], j[n], ans = 0, an = 0;
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &h[i]);
        j[n-1-i] = h[i];
    }
    for (ll i = 0; i < n; i++)
    {
        if(1)
        {
            if(isEmpty(s))
            {
                push(s, i);
                continue;
            }
            else if(h[i] < h[top(s)])
            {
                push(s, i);
                continue;
            }
            while(h[i] > h[top(s)] && !isEmpty(s))
            {
                ll mn = pop(s);
                ans = ans + i - mn + 1;
                if(isEmpty(s)) break;
            }
            push(s, i);
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if(1)
        {
            if(isEmpty(s1))
            {
                push(s1, i);
                continue;
            }
            else if(j[i] < j[top(s1)])
            {
                push(s1, i);
                continue;
            }
            while(j[i] > j[top(s1)] && !isEmpty(s1))
            {
                ll mn = pop(s1);
                an = an + i - mn + 1;
                if(isEmpty(s1)) break;
            }
            push(s1, i);
        }
    }
    printf("%lld", ans+an);
    
}