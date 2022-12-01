#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ll long long
int comp (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
    ll t, k;
    char pp;
    char sub = (char)26;
    int a[1000000], b[1000000];
    scanf("%lld ", &t);
    for (ll o = 0; o < t; o++)
    {
        scanf("%lld ", &k);
        int x = 0, y = 0, z = 0;
        scanf("%c", &pp);
        while(pp != '\n')
        {
            if(pp == ' ')
            {
                z++;
                if(scanf("%c", &pp) == EOF) break;
                continue;
            }
            a[x] = pp + k;
            if(a[x] > 122) a[x] = a[x] - sub;
            x++;
            scanf("%c", &pp);
        }
        scanf("%c", &pp);
        while(pp != '\n')
        {
            if(pp == ' ')
            {
                z--;
                if(scanf("%c", &pp) == EOF) break;
                continue;
            }
            b[y] = pp;
            y++;
            if(scanf("%c", &pp) == EOF) break;
        }
        if(x != y && z == 0) 
        {
            printf("False\n");
            continue;
        }
        qsort(a, x, 4, comp);
        qsort(b, x, 4, comp);
        int c = 0;
        for (int i = 0; i < x; i++)
        {
            if(a[i] != b[i])
            {
                printf("False\n");
                c = 1;
                break;
            }
        }
        if(c == 0)printf("True\n");
    }
}
/*
for (ll i = 0; i < x; i++)
        {
            printf("%c", a[i]);
        }
        printf("\n");
        for (ll i = 0; i < y; i++)
        {
            printf("%c", b[i]);
        }
        printf("\n");  */