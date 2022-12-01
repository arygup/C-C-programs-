#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<assert.h>
#define ll long long int 
int compare(ll *a, ll *b) 
{ 
    return *(ll *) b - *(ll *)a;
}  
void bubbleSort(ll A[], ll size)
{
    ll temp, swap_count = 0;
    if (size == 1) return;
    for (ll i = 0; i < size - 1; i = i + 1)
    {
        if (A[i] > A[i + 1])continue;
        else
        {
            temp = A[i];
            A[i] = A[i + 1];
            A[i + 1] = temp;
            ++swap_count;
        }
    }
    if (swap_count > 0) bubbleSort(A, size - 1);
}
int main()
{
    ll n, count;
    scanf("%lld %lld", &count, &n);
    ll A[count], B[count], c = 0, ch = 0;
    for (ll i = 0; i < count; i++)
    {
        scanf("%lld", &A[i]);
    }
    B[0] = A[count - 1];
    for (ll i = 1; i < count; i++)
    {
        B[i] = B[i - 1] + A[count - i - 1];
    }
    // for (ll i = 0; i < count; i++)
    // {
    //     printf("%lld ", B[i]);
    // }
    ll ans = B[count - 1];
    //printf("  %lld   ", ans);
    //B[count - 1] = -__LONG_LONG_MAX__;
    ll cjj = B[count - 1], x = 0;
    //qsort(B, count, sizeof(B[0]), compare);
    bubbleSort(&B[0], count);
    for (ll i = 0; i < n - 1; i++)
    {
        if(B[i] == cjj) x = 1;
        ans = ans + B[i + x];
    }
    printf("%lld ", ans);
}