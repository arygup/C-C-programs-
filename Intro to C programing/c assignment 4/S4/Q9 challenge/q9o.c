#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(char *a, char *b)
{
    return strcmp(a, b);
}
int main(int a, char *aa[a])
{
    char in[101];
    int B[257] = {0}, C[257] = {0}, D[257] = {0}, E[257] = {0}; // F[257] = {0}, G[257] = {0}, H[257] = {0}, I[257] = {0};
    FILE *file, *ans, *alp[257];
    file = fopen(aa[1], "r");
    while (fscanf(file, "%s", in) != EOF)
    {
        if (in[1] <= 55)
        {
            char buf[0x100];
            snprintf(buf, sizeof(buf), "%d00.txt", (int)in[0]);
            alp[(int)in[0]] = fopen(buf, "a");
            fprintf(alp[(int)in[0]], "%s\n", in);
            fclose(alp[(int)in[0]]);
            B[(int)in[0]]++;
        }
        else if (in[1] <= 78)
        {
            char buf[0x100];
            snprintf(buf, sizeof(buf), "%d01.txt", (int)in[0]);
            alp[(int)in[0]] = fopen(buf, "a");
            fprintf(alp[(int)in[0]], "%s\n", in);
            fclose(alp[(int)in[0]]);
            C[(int)in[0]]++;
        }
        else if (in[1] <= 101)
        {
            char buf[0x100];
            snprintf(buf, sizeof(buf), "%d02.txt", (int)in[0]);
            alp[(int)in[0]] = fopen(buf, "a");
            fprintf(alp[(int)in[0]], "%s\n", in);
            fclose(alp[(int)in[0]]);
            D[(int)in[0]]++;
        }
        // else if (in[1] <= 80)
        // {
        //     char buf[0x100];
        //     snprintf(buf, sizeof(buf), "%d03.txt", (int)in[0]);
        //     alp[(int)in[0]] = fopen(buf, "a");
        //     fprintf(alp[(int)in[0]], "%s\n", in);
        //     fclose(alp[(int)in[0]]);
        //     E[(int)in[0]]++;
        // }
        // else if (in[1] <= 91)
        // {
        //     char buf[0x100];
        //     snprintf(buf, sizeof(buf), "%d04.txt", (int)in[0]);
        //     alp[(int)in[0]] = fopen(buf, "a");
        //     fprintf(alp[(int)in[0]], "%s\n", in);
        //     fclose(alp[(int)in[0]]);
        //     F[(int)in[0]]++;
        // }
        // else if (in[1] <= 103)
        // {
        //     char buf[0x100];
        //     snprintf(buf, sizeof(buf), "%d05.txt", (int)in[0]);
        //     alp[(int)in[0]] = fopen(buf, "a");
        //     fprintf(alp[(int)in[0]], "%s\n", in);
        //     fclose(alp[(int)in[0]]);
        //     G[(int)in[0]]++;
        // }
        // else if (in[1] <= 114)
        // {
        //     char buf[0x100];
        //     snprintf(buf, sizeof(buf), "%d06.txt", (int)in[0]);
        //     alp[(int)in[0]] = fopen(buf, "a");
        //     fprintf(alp[(int)in[0]], "%s\n", in);
        //     fclose(alp[(int)in[0]]);
        //     H[(int)in[0]]++;
        // }
        else 
        {
            char buf[0x100];
            snprintf(buf, sizeof(buf), "%d03.txt", (int)in[0]);
            alp[(int)in[0]] = fopen(buf, "a");
            fprintf(alp[(int)in[0]], "%s\n", in);
            fclose(alp[(int)in[0]]);
            E[(int)in[0]]++;
        }
    }
    fclose(file);
    ans = fopen(aa[2], "w");
    for (int i = 0; i < 257; i++)
    {
        if (B[i] != 0)
        {
            int x = 0;
            char temp[B[i]][101], ch;
            char buf[0x100];
            snprintf(buf, sizeof(buf), "%d00.txt", i);
            alp[(int)in[0]] = fopen(buf, "r");
            while (fscanf(alp[i], "%s", in) != EOF)
            {
                strcpy(temp[x], in);
                x++;
            }
            fclose(alp[i]);
            qsort(temp, B[i], 101 * sizeof(char), compare);
            for (int j = 0; j < B[i]; j++)
            {
                fprintf(ans, "%s\n", temp[j]);
            }
            remove(buf);
        }
        if (C[i] != 0)
        {
            int x = 0;
            char temp[C[i]][101], ch;
            char buf[0x100];
            snprintf(buf, sizeof(buf), "%d01.txt", i);
            alp[(int)in[0]] = fopen(buf, "r");
            while (fscanf(alp[i], "%s", in) != EOF)
            {
                strcpy(temp[x], in);
                x++;
            }
            fclose(alp[i]);
            qsort(temp, C[i], 101 * sizeof(char), compare);
            for (int j = 0; j < C[i]; j++)
            {
                fprintf(ans, "%s\n", temp[j]);
            }
            remove(buf);
        }
        if (D[i] != 0)
        {
            int x = 0;
            char temp[D[i]][101], ch;
            char buf[0x100];
            snprintf(buf, sizeof(buf), "%d02.txt", i);
            alp[(int)in[0]] = fopen(buf, "r");
            while (fscanf(alp[i], "%s", in) != EOF)
            {
                strcpy(temp[x], in);
                x++;
            }
            fclose(alp[i]);
            qsort(temp, D[i], 101 * sizeof(char), compare);
            for (int j = 0; j < D[i]; j++)
            {
                fprintf(ans, "%s\n", temp[j]);
            }
            remove(buf);
        }
        if (E[i] != 0)
        {
            int x = 0;
            char temp[E[i]][101], ch;
            char buf[0x100];
            snprintf(buf, sizeof(buf), "%d03.txt", i);
            alp[(int)in[0]] = fopen(buf, "r");
            while (fscanf(alp[i], "%s", in) != EOF)
            {
                strcpy(temp[x], in);
                x++;
            }
            fclose(alp[i]);
            qsort(temp, E[i], 101 * sizeof(char), compare);
            for (int j = 0; j < E[i]; j++)
            {
                fprintf(ans, "%s\n", temp[j]);
            }
            remove(buf);
        }
        // if (F[i] != 0)
        // {
        //     int x = 0;
        //     char temp[F[i]][101], ch;
        //     char buf[0x100];
        //     snprintf(buf, sizeof(buf), "%d04.txt", i);
        //     alp[(int)in[0]] = fopen(buf, "r");
        //     while (fscanf(alp[i], "%s", in) != EOF)
        //     {
        //         strcpy(temp[x], in);
        //         x++;
        //     }
        //     fclose(alp[i]);
        //     qsort(temp, F[i], 101 * sizeof(char), compare);
        //     for (int j = 0; j < F[i]; j++)
        //     {
        //         fprintf(ans, "%s\n", temp[j]);
        //     }
        //     remove(buf);
        // }
        // if (G[i] != 0)
        // {
        //     int x = 0;
        //     char temp[G[i]][101], ch;
        //     char buf[0x100];
        //     snprintf(buf, sizeof(buf), "%d05.txt", i);
        //     alp[(int)in[0]] = fopen(buf, "r");
        //     while (fscanf(alp[i], "%s", in) != EOF)
        //     {
        //         strcpy(temp[x], in);
        //         x++;
        //     }
        //     fclose(alp[i]);
        //     qsort(temp, G[i], 101 * sizeof(char), compare);
        //     for (int j = 0; j < G[i]; j++)
        //     {
        //         fprintf(ans, "%s\n", temp[j]);
        //     }
        //     remove(buf);
        // }
        // if (H[i] != 0)
        // {
        //     int x = 0;
        //     char temp[H[i]][101], ch;
        //     char buf[0x100];
        //     snprintf(buf, sizeof(buf), "%d06.txt", i);
        //     alp[(int)in[0]] = fopen(buf, "r");
        //     while (fscanf(alp[i], "%s", in) != EOF)
        //     {
        //         strcpy(temp[x], in);
        //         x++;
        //     }
        //     fclose(alp[i]);
        //     qsort(temp, H[i], 101 * sizeof(char), compare);
        //     for (int j = 0; j < H[i]; j++)
        //     {
        //         fprintf(ans, "%s\n", temp[j]);
        //     }
        //     remove(buf);
        // }
        // if (I[i] != 0)
        // {
        //     int x = 0;
        //     char temp[I[i]][101], ch;
        //     char buf[0x100];
        //     snprintf(buf, sizeof(buf), "%d07.txt", i);
        //     alp[(int)in[0]] = fopen(buf, "r");
        //     while (fscanf(alp[i], "%s", in) != EOF)
        //     {
        //         strcpy(temp[x], in);
        //         x++;
        //     }
        //     fclose(alp[i]);
        //     qsort(temp, I[i], 101 * sizeof(char), compare);
        //     for (int j = 0; j < I[i]; j++)
        //     {
        //         fprintf(ans, "%s\n", temp[j]);
        //     }
        //     remove(buf);
        // }
    }
    fclose(ans);
    return 0;
}