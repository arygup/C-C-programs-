#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long count, n, p, temp, ans;
    scanf("%lld", &count);
    for (long long i = 0; i < count; i++)
    {
        p = 0;
        ans = 0;
        long long A[1000] = {0};
        scanf("%lld", &n);
        temp = n;
        while (temp >= 1)
        {
            p++;
            A[p] = temp%2;
            temp = temp / 2;
        }
        for (long long j = 1; j < p; j++)
        {
            if(A[j] == 0) ans++;
            if(A[j] == 1) break;
        }
        printf("%lld\n", ans+1);
    }
}