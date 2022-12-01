#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define ll long long
ll n, A[1001], c = 0;
ll sub(ll i, ll find)
{
    ll ret = 0;
    ll imp = 1;
    ll dec = A[i];    //either dec by element or we ignore
    if (i != n) 
    {
        sub(i + imp, find - dec);   //index increased by imp
        sub(i + imp, find);
        return ret;   // next call
    }
    if (find == 0) 
    {
        c++;    
    }
    return ret;
}
int main()
{
    ll k;
    scanf("%lld %lld", &n, &k);
    for (ll i = 0; i < n; i++)
    {
        scanf("%lld", &A[i]);
    }
    int index = 0;
    sub(index, k);
    printf("%lld", c);
    return 0;
}

/// 1 3 2 4 6 43 1 3 5 1 2 