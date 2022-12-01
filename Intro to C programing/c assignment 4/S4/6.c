#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int a, char *aa[a])
{
    double n = 0, sum = 0, x, v = 0, m = 0;
    int A[300] = {0};
    char in[300];
    FILE *file[a-1], *ans;
    for (int i = 2; i < a; i++)
    {
        file[i] = fopen(aa[i], "r");
        while (fscanf(file[i], "%s", in) != EOF)
        {
            for (int i = 0; i < strlen(in) + 1; i++)
            {
                if ((int)in[i] == 0)
                    continue;
                A[(int)in[i]]++;
            }
        }
    }
    ans = fopen(aa[1], "w");
    for (int i = 48; i < 58; i++) 
    {
        fprintf(ans, "%c:%d\n", (char)i, A[i]);
    }
    for (int i = 65; i < 91; i++) 
    {
        fprintf(ans, "%c:%d\n", (char)i, A[i]);
    }
    for (int i = 97; i < 122; i++) 
    {
        fprintf(ans, "%c:%d\n", (char)i, A[i]);
    }
    int charec = 122;
    fprintf(ans, "%c:%d", (char)charec, A[122]);
    for (int i = 2; i < a; i++)
    {
        fclose(file[i]);
    }
    fclose(ans);
    return 0;
}