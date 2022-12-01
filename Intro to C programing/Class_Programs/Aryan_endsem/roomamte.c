#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
#define m 1000000007ll
int main()
{
    ll a = 0, b = 0, sol = 0, c = 1;
    char in[1000000];
    scanf("%s", in);
    for(ll i = 0; i<strlen(in); i++)
    {
        if(in[i] == 'a')
       {
           a++;
       }
       if(in[i] == 'b')    
       {                   
           b++;
       }
       if(a == b)  
       {
           sol++;
       }
    }
    if(a!=b)
    {
        printf("0");
        return 0;
    }
    for(int i = 0; i < sol - 1; ++i)
    {
        c = (c * 2ll) % m;
    }
    printf("%lld", c);
    return 0;
}
