/* check if the entered number can be represented as the sum of numbers given in 
the array, if array less 5 elements just repeat last element multiple times */
#include <bits/stdc++.h>
using namespace std;
int f(int n,int A[], int B[])
{
    if(n < 0)
    {
        return 0;
    }
    if(n == 0)
    {
        return 1;
    }
    if(B[n] > -1) return B[n];
    int x = 0;
    for (int i = 0; i < 5; i++)
    {
        x = x + f((n-A[i]), A, B);
    }
    B[n] = x;
    return x;
}
int main()
{
    int n, A[5];
    int x;
    x = 0;
    scanf("%d", &n);
    int B[n+1];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n+1; i++)
    {
        B[i] = -2;
    }
    x = f(n, A, B);
    bool y;
    y = x;
    cout << y;
    return 0;
}
