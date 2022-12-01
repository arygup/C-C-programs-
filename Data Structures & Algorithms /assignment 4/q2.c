#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<assert.h>
#define ll long long int 
int compare(ll *a, ll *b) 
{ 
    return *b - *a;
} 
int main()
{
    ll n, count;
    scanf("%lld %lld", &count, &n);
    ll A[count], c = 0, ch = 0;
    for (ll i = 0; i < count; i++)
    {
        scanf("%lld", &A[i]);
        if(i > 0) if(A[i] < A[i - 1]) ch++;
    }
    if(!ch)
    {
        printf("0");
        return 0;
    }
    for (ll i = 0; i < count; i++)
    {
        if(A[i] > n)
        {
            ll t = n;
            n = A[i];
            A[i] = t;
            c++;
        }
        ch = 0;
        for (ll j = 1; j < count; j++)
        {
            if(A[j] < A[j - 1])
            { 
                ch++;
                break;
            }
        }
        if(!ch)
        {
            printf("%lld ", c);
            return 0;
        }
    }
    printf("-1");
}