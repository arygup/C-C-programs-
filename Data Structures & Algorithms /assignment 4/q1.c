#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<assert.h>
#define ll long long int 
int compare(ll *a, ll *b) 
{ 
    return *b - *a;
} 
int main()
{
    ll n, count;
    scanf("%lld", &count);
    for (ll co = 0; co < count; co++)
    {
        scanf("%lld", &n);
        ll A[n], max = 0, f = 1, maxf = 0, x = 0;
        for (ll i = 0; i < n; i++)
        {
            scanf("%lld", &A[i]);
        }
        qsort(A, n, sizeof(A[0]), compare);
        // for (ll i = 0; i < n; i++)
        // {
        //     printf("%lld ", A[i]);
        // }
        printf("\n");
        for (ll i = 1; i < n; i++)
        {
            if(A[i] == A[i - 1])
            {
                x++;
                f++;
                if( (f == max && i != n-1 && A[i] != A[i+1])  ||  (f == max && i == n-1))
                {
                    maxf++;
                }
                else if(f > max)
                {
                    max = f;
                    maxf = 1;
                }
            }
            else if(A[i] != A[i - 1])
            {
                f = 1;
            }
        }
        //printf("%lld %lld", maxf, max);
        if(x == 0)
        {
            printf("%lld ", n);
        }
        // if(maxf == 1)
        // {
        //     if(max != 1) printf("%lld ", (n-max)/(max-1));
        //     if(max == 1) printf("%lld", n);
        // }
        else 
        {
            printf("%lld ", maxf + (n - max*maxf)/(max - 1) - 1);
        }
    }
}
// 1  4      1 2 3 4

// 1  16     7 8 7 8 7 8 1 7 8 7 8 7 8 2 8 7

// 1  16     1 2 3 1 2 3 1 2 3 4 1 2 3 1 2 3

// 1   8     2 3 4 5 4 3 5 2