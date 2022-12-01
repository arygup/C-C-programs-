#include<stdio.h>
#include<stdlib.h>
int main(int a, char *aa[a])
{
    double n = 0, sum = 0, x;
    FILE *file, *ans;
    file = fopen(aa[1], "r");
    while(fscanf(file, "%lf", &x) != EOF)   
    {
        n++;
        sum = sum + x;
    }
    double y;
    y = (double)sum/(double)n;
    ans = fopen(aa[2], "w");
    fprintf(ans, "%lf", y);
    fclose(ans);
    fclose(file);
    return 0;
}
