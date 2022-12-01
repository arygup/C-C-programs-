#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t, n, temp;
    scanf("%lld", &t);
    for (long long i = 0; i < t; i++)
    {
        scanf("%lld", &n);
        if(n%7 == 0)
        {
            printf("%lld\n", n);
            continue;
        }
        else
        {
            temp = n - (n%10);
            for(int i = 1; i < 10; i++)
            {
                if(((temp+i)%7) == 0)
                {
                    temp = temp + i;
                    break;
                }
            }
            printf("%lld\n", temp);
            continue;
        }
    }
    return 0;
}