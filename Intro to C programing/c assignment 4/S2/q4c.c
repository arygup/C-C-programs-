#include <stdio.h>
#include <stdlib.h>
int main(int a, char *aa[a])
{
    double n = 0, sum = 0, x, v = 0, m = 0,max = 1.2 ,min = 0.8;
    FILE *file, *ans, *mean;
    file = fopen(aa[1], "r");
    mean = fopen(aa[2], "r");
    ans = fopen(aa[3], "w");
    fscanf(mean, "%lf", &m);
    fclose(mean);
    while (fscanf(file, "%lf", &x) != EOF)
    {
        if (x >= min * m && x <= max * m)
        {
            v++;
        }
        n++;
    }
    v = v*100;
    fprintf(ans, "percentage in range:%lf\n", v/n);
    fclose(ans);
    fclose(file);
    return 0;
}
