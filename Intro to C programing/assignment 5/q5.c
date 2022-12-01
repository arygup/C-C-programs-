#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
#define mod 1000000007
ll n, m, h, A[1002], B[1002], C[1000];
ll max(ll a, ll b) 
{
    if(b>a) a = b;
    return a;
}
ll rec(ll q, ll f)
{
    if(q >= n) return 0;
    if(B[q] != -1) return B[q];
    B[q] = 0;
    for (int i = n; i > q; i--)
    {
        if(A[q] > A[i] || q == f - 1)
        {
            B[q] = max(B[q], rec(i, m)+1);
        }
    }
    return B[q];
}
int main()
{
    scanf("%lld %lld", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &A[i]);
        B[i] = -1;
        C[i] = -1;
    }
    B[n] = 1;
    A[n] = 0;
    C[0] = 1;
    ll op = rec(0, m), op2 = 0, op3 = 0;
    for (int i = 1; i < n; i++)
    {
        op = max(op, rec(i, m));
        
    }
    printf("%lld ", op);
    return 0;
}
