#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int a, char *aa[a])
{
    char in1[300], in2[300];
    FILE *file1, *file2, *ans;
    ans = fopen(aa[3], "w");
    file1 = fopen(aa[1], "r");
    file2 = fopen(aa[2], "r");
    int x = 0, y = 0, z = 1;
    while ((x != 0) || (y != 0) || (z != 0))
    {
        if (strcmp(in1, in2) == 0)
        {
            y = 0;
        }    
        if (x == 0)
        {
            x = 1;
            if (fscanf(file1, "%s", in1) == EOF)
            {
                fprintf(ans, "%s\n", in2);
                while (fscanf(file2, "%s", in2) != EOF)
                {
                    fprintf(ans, "%s\n", in2);
                }
                x = 0;
                y = 0;
                break;
            }
        }
        if (y == 0)
        {
            y = 1;
            if (fscanf(file2, "%s", in2) == EOF)
            {
                fprintf(ans, "%s\n", in1);
                while (fscanf(file1, "%s", in1) != EOF)
                {
                    fprintf(ans, "%s\n", in1);
                }
                x = 0;
                y = 0;
                break;
            }
        }
        if (strcmp(in1, in2) == 0)
        {
            x = 0;
            fprintf(ans, "%s\n", in2);
        }
        if (strcmp(in1, in2) > 0)
        {
            fprintf(ans, "%s\n", in2);
            y = 0;
        }
        if (strcmp(in1, in2) < 0)
        {
            fprintf(ans, "%s\n", in1);
            x = 0;
        }
        z = 0;
    }
    fclose(ans);
    fclose(file1);
    fclose(file2);
    return 0;
}
