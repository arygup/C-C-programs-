#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define ll long long
int main()
{ 
    ll n, a = 0, b;
    scanf("%lld", &n);
    for (ll i = 2; i < sqrt(n)+1; i++)
    {
        if(n%i == 0)
        {
            a = i;
            b = n/i;
        }
    }
    if(a == 0)
    {
        printf("%lld", n-1);
        return 0;
    }
    printf("%lld", a + b - 2);
    return 0;
}