#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(0));
    int n = 0, m = 0, testcases;
    //printf("input number of test-cases\n");
    scanf("%d", &testcases);
    double p, q, pi, f = 4, g, h, H, G;
    int y, z, x, w, l, k, e, r, E, R, L, K;
    for (int i = 0; i < testcases; i++)
    {
        x = rand();
        y = rand();
        z = rand();
        w = rand();
        l = rand();
        k = rand();
        e = rand();
        r = rand();
        E = rand();
        R = rand();
        L = rand();
        K = rand();
        p = (double)y / (double)z;
        q = (double)w / (double)x;
        g = (double)e / (double)l;
        h = (double)r / (double)k;
        g = (double)e / (double)l;
        h = (double)r / (double)k;
        G = (double)E / (double)L;
        H = (double)R / (double)K;
        p = p + g + G;
        q = q + h + H;
        p = p - (int)p;
        q = q - (int)q;
        if (p * p + q * q <= 1)
            n++;
        if (p * p + q * q > 1)
            m++;
    }
    pi = (double)n / ((double)n + (double)m);
    printf("%lf", pi * f);
}
