#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t, n;
    scanf("%lld", &t);
    for (long long i = 0; i < t; i++)
    {
        scanf("%lld", &n);
        long long B[n], C[n];
        for (long long j = 0; j < n; j++)
        {
            scanf("%lld", &B[j]);
        }
        for (long long j = 0; j < n; j++)
        {
            scanf("%lld", &C[j]);
        }
        long long maxc = C[0], c = 0, mc = 0;
        for (int i = 0; i < n; i++)
        {
            if (C[i] > maxc)
            {
                maxc = C[i];
                c = i;
                mc++;
            }
        }
        long long maxb = B[0], b = 0, mb = 0;
        for (int i = 0; i < n; i++)
        {
            if (B[i] > maxb)
            {
                maxb = B[i];
                b = i;
                mb++;
            }
        }
        int z = 8;
        if (maxb == maxc)
        {
            for (int i = 0; i < n; i++)
            {
                if (B[i] == maxb && C[i] == maxc)
                {
                    printf("%lld \n", maxb * maxc);
                    z = 0;
                    break;
                }
            }
        }
        if (z == 0) continue;
        if (maxb >= maxc)
        {
            for (long long i = 0; i < n; i++)
            {
                if (C[i] > B[i])
                {
                    long long temp = B[i];
                    B[i] = C[i];
                    C[i] = temp;
                }
            }
        }
        if (maxc > maxb)
        {
            for (long long i = 0; i < n; i++)
            {
                if (B[i] > C[i])
                {
                    long long temp = C[i];
                    C[i] = B[i];
                    B[i] = temp;
                }
            }
        }
        int x = sizeof(B) / sizeof(B[0]);
        sort(B, B + x);
        x = sizeof(C) / sizeof(C[0]);
        sort(C, C + x);
        printf("%lld \n", B[n - 1] * C[n - 1]);
    }
    return 0;
}