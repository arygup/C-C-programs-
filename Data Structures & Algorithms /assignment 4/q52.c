#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<assert.h>
#define ll long long int 
ll mini(ll x, ll y, ll z)
{
    if(y<x) x=y;
    if(z<x) x=z;
    return x;
}
int compare(const void *a, const void *b) 
{ 
    return *(ll *) a - *(ll *)b;
} 
ll push(ll*A, ll x, ll i)
{
    A[i] = x;
    ll p = (i-1)/2;
    while (p >= 0 && i != 0)
    {
        if(A[p] > A[i])
        {
            ll t = A[p];
            A[p] = A[i];
            A[i] = t;
        }
        i = p;
        p = (i-1)/2;
    }
    return 0;
}
ll del(ll*A, ll i, ll s)    // curri, size
{
    ll l = i*2 + 1, r = i*2 + 2;
    if(l <= s && r <= s)
    {
        ll mi = mini(A[i], A[l], A[r]);
        if(A[i] == mi) return 0;
        if(A[l] == mi)
        {
            A[l] = A[i];
            A[i] = mi;
            del(A, l, s);
            return 0;
        }
        if(A[r] == mi)
        {
            A[r] = A[i];
            A[i] = mi;
            del(A, r, s);
            return 0;
        }
    }
    if(l <= s)
    {
        ll mi = mini(A[i], A[l], __LONG_LONG_MAX__);
        if(A[i] == mi) return 0;
        if(A[l] == mi)
        {
            A[l] = A[i];
            A[i] = mi;
            del(A, l, s);
            return 0;
        }
    }
    return 0;
}
ll* make(ll*A, ll*B, ll n)
{
    ll C[n*n], s = 0, *F = (ll *)malloc(__SIZEOF_LONG_LONG__*n);
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            if(A[i] + B[j] <= A[0] + B[n-1] && A[i] + B[j] <= B[0] + A[n-1])
            {
                //s++;
                push(C, A[i] + B[j], s);
                s++;
            }
            else
            {
                break;
            }
        }
    }
    for (ll i = 0; i < n; i++)
    {
        F[i] = C[0];
        C[0] = C[s - 1];
        s--;
        del(C, 0, s);
    }
    return F;
}
int main()
{
    ll testcas, n, *a, *b;
    scanf("%lld", &testcas);
    for (ll test = 0; test < testcas; test++)
    {
        scanf("%lld", &n);
        ll A[n][n], *B[n*n], s = 0, *op = malloc(__SIZEOF_LONG_LONG__*(n + 1)), t = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++) scanf("%lld", &A[i][j]);                     
            qsort(&A[i][0], n, sizeof(ll), compare);
        }   
        a = make(&A[0][0], &A[1][0], n);
        //qsort(a, n, __SIZEOF_LONG_LONG__, compare);
        //a = make(a, &A[2][0], n);
        // 3 6 7
        for (ll i = 2; i < n; i++)
        {
            a = make(&A[i][0], a, n);
        }
        for (ll i = 0; i < n; i++)
        {
            printf("%lld ", a[i]);
        }
        printf("\n");
    }
}