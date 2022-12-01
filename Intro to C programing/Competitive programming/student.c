#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int bs(int C[26])
{
    int t;
    int a = 0;
    for (int i = 1; i < n; i++)
    {
        if (A[i-1] > A[i])
        {
            t = A[i];
            A[i] = A[i-1];
            A[i-1] = t;
            a++;
        }
    }
    if (a != 0)
        bs(n - 1, A);
    return 0;
}
int main()
{
    long long n, k;
    scanf("%lld %lld", &n, &k);
    char A[n], B[26];
    scanf("%s", A);
    int C[26] = {0};
    for (int i = 0; i < 26; i++)
    {
        B[i] = 'a' + i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if(A[i] == B[j]) C[j]++;
        }
    }
    bs(C);
    for (int i = 0; i < K; i++)
    {
        
    }
    


    return 0;
}