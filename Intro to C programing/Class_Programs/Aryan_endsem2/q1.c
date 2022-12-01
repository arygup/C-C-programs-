#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
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
    if(b > a) a = b;
    return a;
}
int comp (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
    ll n;
    double t = 0, d;
    scanf("%lld %lf", &n, &t);
    double A[n][2], avg = 0, sum = 0;
    for (ll i = 0; i < n; i++)
    {
        scanf("%lf %lf", &A[i][0], &A[i][1]);
        avg = avg + A[i][0]*A[i][1];
        sum = sum + A[i][1];
    }
    avg = avg/sum;
    avg = avg/n;
    for (ll i = 0; i < n; i++)
    {
        d = avg - A[i][0];
        //d = max(d, -d);
        if(d/A[i][1] > t)
        {
            t = d/A[i][1];
        }
    }
    printf("%lf", t);
    return 0;
}
