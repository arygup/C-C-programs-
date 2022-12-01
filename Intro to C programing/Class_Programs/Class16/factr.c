#include <stdio.h>  //recursive version of fact.c

int loop_factn(int n)
{
    int fact_n = 1;

    for (int i = 1; i <= n; i++)
    {
        fact_n = fact_n * i;
    }
    return fact_n;
}

int recursive_factn (int n)

{
    int fact_n = 1;

    if (n == 0)
    {
        fact_n = 1;
    }
    else 
    {
        fact_n = n * recursive_factn(n-1);
    }
    return fact_n;
}

int main()
{
    int n, loop_fact_n = 0, recursive_fact_n = 0;
    scanf("%d", &n);

    loop_fact_n = loop_factn(n);
    recursive_fact_n = recursive_factn(n);

    printf("using loop !%d = %d\n", n, loop_fact_n);
    printf("using recursion !%d = %d\n", n, recursive_fact_n);

    return 0;

}