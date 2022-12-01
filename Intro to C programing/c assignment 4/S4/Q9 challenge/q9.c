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
    int B[257] = {0};
    FILE *file, *ans, *alp[257];
    file = fopen(aa[1], "r");
    while(fscanf(file, "%s", in) != EOF)
    {
        char buf[0x100];
        snprintf(buf, sizeof(buf), "%d.txt", (int)in[0]);     
        alp[(int)in[0]] = fopen(buf , "a");                   
        fprintf(alp[(int)in[0]], "%s\n", in);
        fclose(alp[(int)in[0]]);
        B[(int)in[0]]++;
    }
    fclose(file);
    ans = fopen(aa[2], "w");
    for (int i = 0; i < 257; i++)
    {
        if(B[i] == 0) continue;
        int x = 0;
        char temp[B[i]][101], ch;
        char buf[0x100];
        snprintf(buf, sizeof(buf), "%d.txt", i);
        alp[(int)in[0]] = fopen(buf , "r");
        while(fscanf(alp[i], "%s", in) != EOF)
        {
            strcpy(temp[x], in);
            x++;
        }
        fclose(alp[i]);
        qsort(temp, B[i], 101*sizeof(char), compare);
        for (int j = 0; j < B[i]; j++)
        {
            fprintf(ans, "%s\n", temp[j]);
        }
        remove(buf);
    }
    fclose(ans);
    return 0;
}    