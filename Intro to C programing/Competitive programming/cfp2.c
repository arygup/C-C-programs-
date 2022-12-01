#include <stdio.h>
long long mod(long long x, long long m)
{
	x = (x % m);
	return x;
}
long long fib(long long n, long long F[], long long m)
{
	if (F[n] != 0)
		return F[n];
	F[n] = mod(fib(n - 1, F, m) + fib(n - 2, F, m), m);
	return mod(F[n], m);
}
int main()
{
	long long q, n, m, j, k;
	char ch;
	scanf("%lld %lld %lld ", &n, &q, &m);
	long long F[n + 2], A[n], B[n];
	for (int i = 0; i < n; i++)
		scanf("%lld ", &A[i]);
	for (int i = 0; i < n; i++)
		scanf("%lld ", &B[i]);	
	for (int i = 3; i < n + 2; i++)
		F[i] = 0;
	for (int i = 1; i < 3; i++)
		F[i] = 1;
	F[n+1] = fib(n+1, F, m);
	for (long long i = 0; i < q; i++)
	{
	    scanf("%c %lld %lld ", &ch, &j, &k);
        printf("%c %lld %lld\n", ch, j, k);
		// for (int l = j; l <= k; l++)
		// {
		// 	if (ch == 'A')
		// 	{
		// 		A[l - 1] = mod(A[l - 1] + F[l], m);
		// 	}
		// 	if (ch == 'B')
		// 	{
		// 		B[l - 1] = mod(B[l - 1] + F[l], m);
		// 	}
		// }
		// int check = 0;
		// for (int v = 0; v < n; v++)
		// {
		// 	if (A[v] != B[v])
		// 	{
		// 		check = 1;
		// 	}
		// }
		// if (check == 0)
		// 	printf("YES\n");
		// else if(check > 0)
		// 	printf("NO\n");
        // check = 0;    
	}
	return 0;
}
