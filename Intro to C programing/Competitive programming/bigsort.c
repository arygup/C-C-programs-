#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_word_ln 200
#define wpf 10 // wpf == words per file

int main(int argc, char *argv[])
{
    FILE *mainfile;
    mainfile = fopen(argv[1], "r");

    FILE *outfile;
    outfile = fopen(argv[2], "w");

    FILE *file1, *file2, *filec;
    file1 = fopen("tf1.txt", "w");
    file2 = fopen("tf2.txt", "w");

    char *temp, arr1[wpf][max_word_ln], arr2[wpf][max_word_ln];

    temp = (char*)malloc(max_word_ln);

    int num2 = 1;
    int num1 = 1;
    int ret = fscanf(mainfile, "%s", temp);
    if (ret != -1)
        strcpy(arr1[0], temp);

    for (int i = 1; i < wpf; i++)
    {
        int ret = fscanf(mainfile, "%s", temp);
        if (ret == -1)
            break;
        num1++;

        int l = 0, u = i, mid = i / 2;

        while (u > (l + 1))
        {
            if (strcmp(temp, arr1[mid]) < 0)
            {
                u = mid;
                mid = (u + l) / 2;
                continue;
            }

            else if (strcmp(temp, arr1[mid]) > 0)
            {
                l = mid;
                mid = (u + l) / 2;
                continue;
            }

            break;
        }

        if (strcmp(temp, arr1[mid]) > 0)
        {
            for (int k = i; k > mid; k--)
            {
                char copstr[max_word_ln];
                strcpy(copstr, arr1[k]);
                strcpy(arr1[k], arr1[k + 1]);
                strcpy(arr1[k + 1], copstr);
            }

            strcpy(arr1[mid + 1], temp);
        }

        else

        {
            for (int k = i; k > mid - 1; k--)
            {
                char copstr[max_word_ln];
                strcpy(copstr, arr1[k]);
                strcpy(arr1[k], arr1[k + 1]);
                strcpy(arr1[k + 1], copstr);
            }

            strcpy(arr1[mid], temp);
        }
    }
    
    for(int j=0;j<num1;j++)printf("arr1 : %s\n", arr1[j]);

    printf("bruh Im not changing the array 1 after this, but see \n");
    
    ret = fscanf(mainfile, "%s", temp);
    if (ret != -1)
        strcpy(arr2[0], temp);

    for (int i = 1; i < wpf; i++)
    {
        int ret = fscanf(mainfile, "%s", temp);
        if (ret == -1)
            break;
        num2++;

        int l = 0, u = i, mid = i / 2;

        while (u > (l + 1))
        {
            if (strcmp(temp, arr2[mid]) < 0)
            {
                u = mid;
                mid = (u + l) / 2;
                continue;
            }

            else if (strcmp(temp, arr2[mid]) > 0)
            {
                l = mid;
                mid = (u + l) / 2;
                continue;
            }

            break;
        }

        if (strcmp(temp, arr2[mid]) > 0)
        {
            for (int k = i; k > mid; k--)
            {
                char copstr[max_word_ln];
                strcpy(copstr, arr2[k]);
                strcpy(arr2[k], arr2[k + 1]);
                strcpy(arr2[k + 1], copstr);
            }

            strcpy(arr2[mid + 1], temp);
        }

        else

        {
            for (int k = i; k > mid - 1; k--)
            {
                char copstr[max_word_ln];
                strcpy(copstr, arr2[k]);
                strcpy(arr2[k], arr2[k + 1]);
                strcpy(arr2[k + 1], copstr);
            }

            strcpy(arr2[mid], temp);
        }
    }

      for(int j=0;j<num1;j++)printf("arr1 : %s\n", arr1[j]);

   // for (int i = 0; i < num2; i++)  printf("arr2 : %s\n", arr2[i]);

    return 0;
}