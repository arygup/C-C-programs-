#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int bs(int x, char A[x][21])
{
    int a = 0;
    char t[21];
    for (int i = 1; i < x; i++)
    {
        if (strcmp(A[i - 1], A[i]) > 0)
        {
            strcpy(t, A[i]);
            strcpy(A[i], A[i - 1]);
            strcpy(A[i - 1], t);
            a++;
        }
    }
    if (a != 0)
        bs(x - 1, A);
    return 0;
}
int main(int a, char *aa[a])
{
    char in[21], A[1001][21], *inf;
    int x = 0;
    FILE *file[a - 1], *ans;
    for (int i = 2; i < a; i++)
    {
        file[i] = fopen(aa[i], "r");
        while (fscanf(file[i], "%s", in) != EOF)
        {
            strcpy(&A[x][0], in);
            x++;
        }
    }
    bs(x, A);
    ans = fopen(aa[1], "w");
    int y = 1;
    for (int i = 0; i < x; i++)
    {
        if (i == x - 1)
        {
            fprintf(ans, "%s:%d", &A[i][0], y);
            for (int i = 2; i < a; i++)
            {
                fclose(file[i]);
            }
            fclose(ans);
            return 0;
        }
        if (strcmp(&A[i][0], &A[i + 1][0]) != 0)
        {
            fprintf(ans, "%s:%d\n", &A[i][0], y);
            y = 0;
        }
        y++;
    }
    for (int i = 2; i < a; i++)
    {
        fclose(file[i]);
    }
    fclose(ans);
    return 0;
}