#include <stdio.h>

int loop_factn(int n)
{
    int fact_n = 1;

    for (int i = 1; i <= n; i++)
    {
        fact_n = fact_n * i;
    }
    return fact_n;
}


int main()
{
    int n, fact_n;
    scanf("%d", &n);

    fact_n = loop_factn(n);

    printf("!%d = %d\n", n, fact_n);

    return 0;

}