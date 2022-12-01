#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define ll long long
ll compare (const void * a, const void * b) {
    return ( *(ll*)a - *(ll*)b );
}
int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    ll A[n], B[m], x = 0;
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &A[i]);
    }
    for (ll i = 0; i < m; i++)
    {
        scanf("%lld", &B[i]);
    }
    qsort(A, n, __SIZEOF_LONG_LONG__, compare);
    qsort(B, m, __SIZEOF_LONG_LONG__, compare);
    ll i = 0, j = 0;
    while(i<n && j<m)
    {
        if(A[i] < B[j])
        {
            i++;
            if(i > n) break;
        }
        if(B[j] < A[i])
        {
            j++;
            if(j > m) break;
        }
        if(A[i] == B[j])
        {
            x++;
            j++;
            i++;
            if(i > n) break;
            if(j > m) break;
        }
    }
    printf("%lld", x);
}