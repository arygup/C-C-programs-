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
    stack s = malloc(sizeof(struct stacks));
    assert(s != NULL);
    ll n;
    scanf("%lld", &n);
    s->n = n;
    s->array = malloc(__SIZEOF_LONG_LONG__*n);
    s->top = -1;
    ll x, el = 0;
    int f = 1;
    while(1)
    {
        if(el >= n && f == 1)
        {
            if(top(s) != x)
            {
                push(s, x);
            } 
            break;
        } 
        if(f)
        {
            el++;
            scanf("%lld", &x);
            f = 0;
            //continue;
        } 
        if(isEmpty(s))
        {
            push(s, x);
            f = 1;
            continue;
        }
        if(gcd(x, top(s)) == 1)    // 1 2 3 4 5 6 
        {
            push(s, x);
            f = 1;
            continue;
        }
        if(gcd(x, top(s)) > 1)
        {
            x = lcm(top(s), x);
            pop(s);
            f = 0;
            //continue;
        }
    }
    printf("%lld \n", size(s)); 
    stack s1 = malloc(sizeof(struct stacks));
    assert(s1 != NULL);
    s1->n = n;
    s1->array = malloc(__SIZEOF_LONG_LONG__*n);
    s1->top = -1;
    while(isEmpty(s) == 0)
    {
        push(s1, pop(s));
    }
    while(isEmpty(s1) == 0)
    {
        printf("%lld ", pop(s1));
    }
}