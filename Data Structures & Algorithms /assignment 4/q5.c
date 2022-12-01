#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<assert.h>
#define ll long long int 
int compare(ll *a, ll *b) 
{ 
    return *(ll *) a - *(ll *)b;
}  
ll mini(ll x, ll y, ll z)
{
    if(y<x) x=y;
    if(z<x) x=z;
    return x;
}
ll push(ll**B, ll *x, ll i)    // pointers to pointer, pointer to op, index
{
    B[i] = x;
    ll p = (i-1)/2;
    while (p >= 0 && i != 0)
    {
        if(B[p][0] > B[i][0])
        {
            ll *t = B[p];
            B[p] = B[i];
            B[i] = t;
        }
        i = p;
        p = (i-1)/2;
    }
    return 0;
}
ll del(ll**B, ll i, ll s)    // pointer BrrBy, curri, size
{
    ll l = i*2 + 1, r = i*2 + 2;
    if(l <= s && r <= s)
    {
        ll mi = mini(B[i][0], B[l][0], B[r][0]);        ////////
        if(B[i][0] == mi) return 0;
        if(B[l][0] == mi)
        {
            ll* t = B[l];
            B[l] = B[i];
            B[i] = B[l];
            del(B, l, s);
            return 0;
        }
        if(B[r][0] == mi)
        {
            ll* t = B[r];
            B[r] = B[i];
            B[i] = t;
            del(B, r, s);
            return 0;
        }
    }
    if(l <= s)
    {
        ll mi = mini(B[i][0], B[l][0], __LONG_LONG_MAX__);      /////
        if(B[i][0] == mi) return 0;
        if(B[l][0] == mi)
        {
            ll* t = B[l];
            B[l] = B[i];
            B[i] = t;
            del(B, l, s);
            return 0;
        }
    }
    return 0;
}
int main()
{
    ll testcas, n;
    scanf("%lld", &testcas);
    for (ll test = 0; test < testcas; test++)
    {
        scanf("%lld", &n);
        ll A[n][n], *B[n*n], s = 0, *op = malloc(__SIZEOF_LONG_LONG__*(n + 1)), t = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < n; j++) scanf("%lld", &A[i][j]);                     
            qsort(&A[i][0], n, sizeof(A[0][0]), compare);
        }
        for (ll i = 0; i < n; i++)
        {
            op[i+1] = 0;
            s = s + A[i][0];
        }
        op[0] = s;
        s = 0;
        push(B, op, s);
        while (t < n)
        {
            ll* o = B[0];
            B[0] = B[s];
            s--; 
            del(B, 0, s);
            printf("%lld ", o[0]);
            t++;
            for (ll i = 1; i < n+1; i++)           
            {
                ll* temp = malloc(__SIZEOF_LONG_LONG__*(n + 1));
                ll sum = 0;
                for (ll j = 1; j < n+1; j++)
                {
                    if(i == j && o[j] != n)
                    {
                        temp[j] = o[j]+1;
                    }
                    else
                    {
                        temp[j] = o[j];
                    }
                    sum = sum + A[j-1][temp[j]];
                }
                temp[0] = sum;
                s++;
                push(B, temp, s);
            }   
        }
    }
    
}
