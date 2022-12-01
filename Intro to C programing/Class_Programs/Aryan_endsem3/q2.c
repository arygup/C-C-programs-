#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define ll long long
ll n;
int swap(char A[n][100], char B[n][100], int i)
{
    char t[100];
    strcpy(t,A[i]);
    strcpy(A[i], A[i-1]);
    strcpy(A[i-1],t);
    strcpy(t,B[i]);
    strcpy(B[i], B[i-1]);
    strcpy(B[i-1],t);
    return 0;
}
int compare(char A[n][100], char B[n][100], int i)  // i & i - 1
{
    char ta1[100], ta2[100], c1, c2;
    for (int j = 0; j < 100; j++)
    {
        c1 = A[i][j];
        c2 = B[i][j];
        if(c1>=97)c1 = c1 - 'a' + 'A';
        if(c2>=97)c2 = c2 - 'a' + 'A';
        ta1[j] = c1;
        ta2[j] = c2;
    }
    char tb1[100], tb2[100];
    for (int j = 0; j < 100; j++)
    {
        c1 = A[i-1][j];
        c2 = B[i-1][j];
        if(c1>=97)c1 = c1 - 'a' + 'A';
        if(c2>=97)c2 = c2 - 'a' + 'A';
        tb1[j] = c1;
        tb2[j] = c2;
    }
    if(strcmp(ta1, tb1)) return strcmp(ta1, tb1);   // t1 = i t2 = i - 1
    return -1*strcmp(ta2, tb2);
}
int bs(char A[n][100], char B[n][100])
{
    int a = 0;
    for (int i = 1; i < n; i++)
    {
        if(compare(A, B, i)<0) // i and i - 1 
        {
            swap(A, B, i);
            a++;
        }
    }
    if(a!=0) bs(A, B);
    return 0;
}
int main()
{
    scanf("%lld", &n);
    char A[n][100], B[n][100];
    for (ll i = 0; i < n; i++)
    {
        scanf("%s", A[i]);
        scanf("%s", B[i]);
    }
    bs(A, B);
    for (ll i = 0; i < n; i++)
    {
        printf("%s ", A[i]);
        printf("%s\n", B[i]);
    }
    return 0;
}
