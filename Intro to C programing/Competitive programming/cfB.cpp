#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long count, n, x, min, karma;
    scanf("%lld", &count);
    for (long long i = 0; i < count; i++)
    {
        scanf("%lld %lld", &x, &n);
        if(n == 1)
        {
            printf("%lld\n", x);
            continue;
        }
        if (x / n < 3)
        {
            long long friends, cookies;
            friends = n;
            cookies = x;
            long long arr[friends];
            int runs = 0;
            int flag = 1;
            int ptr = 0;
            for (int i = 0; i < friends; i++)
            {
                arr[i] = 0;
            }
            while (cookies != 0)
            {
                if (runs != 0)
                {
                    if (ptr == 0 || ptr == friends - 1)
                        flag = -flag;
                }
                runs++;
                arr[ptr]++;
                if (flag == 1)
                    ptr++;
                if (flag == -1)
                    ptr--;
                cookies--;
            }
            for (int i = 0; i < friends; i++)
            {
                printf("%lld ", arr[i]);
            }
            printf("\n");
            continue;
        }
        min = x / ((2 * n) - 2);
        long long A[n];
        for (long long j = 1; j < n - 1; j++)
        {
            A[j] = 2 * min;
        }
        A[0] = min;
        A[n - 1] = min;
        karma = x % ((2 * n) - 2);
        if (karma <= n)
        {
            for (long long j = 0; j < karma; j++)
            {
                A[j]++;
            }
        }
        else if (karma > n)
        {
            for (long long j = 0; j < n; j++)
            {
                A[j]++;
            }
            karma = karma - n;
            int index;
            index = n - 2;
            while (karma > 0)
            {
                karma--;
                A[index]++;
                index--;
            }
        }
        for (long long j = 0; j < n; j++)
        {
            printf("%lld ", A[j]);
        }
        printf("\n");
    }
    return 0;
}