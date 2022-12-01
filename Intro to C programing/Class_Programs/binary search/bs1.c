// given sorted array find smallest number greater than or equal to number
#include<stdio.h>
#include<stdlib.h>
#define ll long long 
ll a, n = -1 , A[10], min = 0, max = 9, mid;
ll rec(ll min, ll max)
{
    if(min > max) return 0; 
    if(max - min == 1)
    {
        n = A[max];
        return 0;
    } 
    mid = min + (max - min)/2 ;
    if(A[mid] == a)
    {
        n = a;
        return n;
    }
    if(A[mid] > a)
    {
        n = A[mid];
        max = mid;
    }
    if(A[mid] < a)
    {
        min = mid;
    }
    rec(min, max);
    return n;
}
int main()
{
    scanf("%lld", &a);
    for (int i = 0; i < 10; i++)
    {
        A[i] = i*10;
    }
    rec(min, max);
    printf("%lld", n);
}