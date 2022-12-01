// for a given n*m grid find the number of ways you can travel from one diagonal end to another
#include <iostream>
using namespace std;

long long final(int m, int n, long long A[][100])
{
    if(A[n][m]!=0 || A[m][n]!=0) return max(A[m][n], A[n][m]); 
    if(m == 0) return n;
    if(n == 0) return m;
    if(m<=1 || n<=1)return 1;
    A[n][m] = final(m-1, n, A) + final(m, n-1, A);
    return A[n][m];
}
int  main()
{
    int m, n;
    scanf("%d %d", &n, &m);
    long long A[100][100];
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            A[i][j] = 0;
        }  
    }
    A[0][0] = final(m, n, A);
    printf("%lld", A[0][0]);
    return 0;
}
/* 
Time complexity without array storage proportional to 2^(m+n)
but with array m+n
*/