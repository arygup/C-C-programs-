#include <stdio.h>
#include <stdlib.h>
#define ll long long
ll n, x = 0, y, A[33][33];
char s;
int main()
{
    scanf("%lld", &n);
    while (scanf("%c", &s) != EOF)
    {
        if(s == '?') x++;
    }
    printf("%lld", (x+1)*(x+1));
    return 0;
}
