//
// Created by Aryan Gupta on 11/02/22.
//
#include <iostream>
using namespace std;
long long fib(long long n, long long A[])
{
    if(A[n]!=0) return A[n];
    A[n] = fib(n-1, A) + fib(n-2, A);
    return A[n];
}
int main()
{
    long long n;
    scanf("%lld", &n);
    long long  A[n+1];
    for (int i = 3; i<n+1; i++) A[i]=0;
    for (int i = 1; i<3; i++) A[i]=1;
    A[0] = fib(n, A);
    printf("%lld", A[0]);
    return 0;
  printf("hello");
}
