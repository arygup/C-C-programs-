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
    ll n, m, x, min;
    scanf("%lld %lld", &n, &m);
    s->n = n;
    s->array = malloc(__SIZEOF_LONG_LONG__*n);
    s->top = -1;
    ll A[n];
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &A[n - i - 1]);
    }
    if(n == m)
    {
        min = 0;
        for (ll i = 0; i < m; i++)
        {
            if(A[i] <= A[min]) min = i;
        }
        printf("%lld", A[min]);
        return 0;
    }
    min = 0;
    for (ll i = 0; i < m; i++)
    {
        if(A[i] <= A[min]) min = i;
    }
    push(s, min);
    for (ll i = 1; i < n - m; i++)
    {
        if(A[i + m - 1] >= A[top(s)] && top(s) >= i)  
        {
            push(s, top(s));
        }
        else  if(A[i + m - 1] < A[top(s)] && top(s) >= i)
        {
            push(s, i + m - 1);
        } 
        else if(i > top(s))
        {
            min = i;
            for (ll j = i; j < i + m ; j++)
            {
                if(j>=n-1)break;
                if(A[j] < A[min]) min = j;
            }
            push(s, min);
        }
    }
    min = n - m ;
    for (ll i = n - m ; i < n; i++)
    {
        if(A[i] <= A[min]) min = i;
    }
    push(s, min);
    // stack s1 = malloc(sizeof(struct stacks));
    // assert(s1 != NULL);
    // s1->n = n;
    // s1->array = malloc(__SIZEOF_LONG_LONG__*n);
    // s1->top = -1;
    // while(isEmpty(s) == 0)
    // {
    //     push(s1, pop(s));
    // }
    while(isEmpty(s) == 0)
    {
        printf("%lld ", A[pop(s)]);
    }
}


/*

if(A[top(s)] <= A[i] && i - top(s) <= m) push(s, top(s));
        else
        {
            push(s, i);
        }

*/