#include<stdio.h>
#include<string.h>
int bs(int n, char A[n][20])
{
    int a = 0;
    char t[20];
    for (int i = 1; i < n; i++)
    {
        if(strcmp(A[i-1], A[i])>0)
        {
            strcpy(t,A[i]);
            strcpy(A[i], A[i-1]);
            strcpy(A[i-1],t);
            a++;
        }
    }
    if(a!=0) bs(n-1, A);
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    char A[n][20];
    for (int i = 0; i < n; i++)scanf("%s", A[i]);
    bs(n, A);
    for (int i = 0; i < n; i++) printf("%s \n", A[i]);
}