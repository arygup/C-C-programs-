#include<stdio.h>
#include<stdlib.h>
int main(int a, char *aa[a])
{
    double n = 0, sum = 0, x, v = 0, m = 0, sq = 0, vac = 0;
    FILE *file, *ans, *mean;
    file = fopen(aa[1], "r");
    mean = fopen(aa[2], "r");
    ans = fopen(aa[3], "w");
    fscanf(mean, "%lf", &m);
    fclose(mean);
    while(fscanf(file, "%lf", &x) != EOF)   
    {
        n++;
        sum = sum + x;
        sq = sq + x*x;
        v = sq - (sum*sum)/n;
        vac = vac + (x-m)*(x-m);
        fprintf(ans, "n = %d: approximate variance = %lf\n", (int)n, v/(n-1));
    }
    fprintf(ans, "%lf\n", vac/n);
    fclose(ans);
    fclose(file);
    return 0;
}
