#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hi(int n, char A[n+1], int S[27], int k, int j)
{
    int x = 0, temp;
    temp = k;
    for (int i = j; i < n; i++)
    {
        if (S[(int)A[i] - 'a'] == 1)
        {
            x++;
            continue;
        }
        if (S[(int)A[i] - 'a'] == 0)
        {
            if (k <= 0)
                break;
            S[(int)A[i] - 'a'] = 1;
            k--;
            x++;
        }
    }
    k = temp;
    for (int l = 0; l < 27; l++)
    {
        S[l] = 0;
    }
    return x;
}

int main()
{
    int n, k, S[27] = {0}, x = 0, y, t;
    scanf("%d %d", &n, &k);
    char A[n + 1];
    scanf("%s", A);
    y = hi(n, A, S, k, 0);
    t = y;
    if(k>y) t = k;
    for (int j = 1; j < n-t; j++)
    {
        if (A[n] != A[n-1])
        {
            x = hi(n, A, S, k, j);
            if (x > y) y = x;
        }
    }
    printf("%d", y);
    return 0;
}