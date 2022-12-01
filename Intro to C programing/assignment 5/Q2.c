#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
int main()
{
    ll l, k, m, x = 0, y = 0, c = 0, cmt = 1;
    scanf("%lld %lld %lld ", &l, &k, &m);
    int A[k];
    char t;
    for (ll i = 0; i < k; i++)
    {
        scanf("%c", &t);
        printf("%c", t);
        c++;
        if (c >= l)
        {
            return 0;
        }
        if (i >= k - m)
        {
            A[i - k + m] = (int)t;
        }
    }
    printf("\n");
    while (1)
    {
        for (ll i = 0; i < k; i++)
        {
            if (i < m) // 5 3
            {
                t = A[i];
                printf("%c", t);
            }
            else 
            {
                scanf("%c", &t);
                printf("%c", t);
                c++;
                if (c >= l)
                {
                    return 0;
                }
            }
            if (i >= k - m)
            {
                A[i - k + m] = (int)t;
            }
        }
        printf("\n");
    }
    return 0;
}