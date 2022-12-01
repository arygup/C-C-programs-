#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define m 1000000007
long long mod(long long A)
{
    long long mod;
    if (A >= 0)
    {
        mod = A % m;
    }
    if (A < 0)
    {
        mod = m + (A % m);
    }
    return mod;
}
ll max(ll a, ll b)
{
    if(a > b) a = b;
    return a;
}
int comp (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
void bs(ll *ans, ll A[],ll l,ll r,ll key)
{
    if(l > r) return;
    ll mid = l + (r-l)/2;
    if(A[mid] > key)
    {
        bs(ans, A, 0, mid-1, key);
        
    }
    else
    {
        (*ans) = mid + 1;
        bs(ans, A, mid+1, r, key);
    }
}
ll n, q, a1, a2, fin, l, r;
int main()
{
    scanf("%lld", &n);
    ll A[n];
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld", &A[i]);
    } 
    qsort(A ,n , 8, comp);
    scanf("%lld", &q);
    for (ll o = 0; o < q; o++)
    {
        scanf("%lld %lld", &l, &r);
        a2 = 0;
        a1 = a2;
        bs(&a1, A , 0, n-1, l-1);
        bs(&a2, A, 0, n-1, r);
        fin = a2 - a1;
        printf("%lld ", fin);
    }
    return 0;
}