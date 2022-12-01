#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h> //  getch #79
#define max_word_ln 100
#define wpf 100 // wpf == words per file

char temp[max_word_ln], arr1[wpf][max_word_ln] ;  //, arr2[wpf][max_word_ln];
FILE *mainfile, *file1, *file2, *filec, *ansfile, *filex, *filexm;
void sortchunk(FILE* file)
{
    int num1 = 1;
    int ret1 = fscanf(mainfile, "%s", temp);
    if (ret1 != -1)
        strcpy(arr1[0], temp);
    for (int i = 1; i < wpf; i++)
    {
        int ret = fscanf(mainfile, "%s", temp);
        if (ret == -1)
            break;
        num1++;
        int l = 0, u = i, mid = i / 2;
        while (u > (l + 1)) // hjsd
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
            for (int k = i - 1; k > mid; k--)
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
            for (int k = i - 1; k > mid - 1; k--)
            {
                char copstr[max_word_ln];
                strcpy(copstr, arr1[k]);
                strcpy(arr1[k], arr1[k + 1]);
                strcpy(arr1[k + 1], copstr);
            }
            strcpy(arr1[mid], temp);
        }
    }
    for (int j = 0; j < num1; j++)
        fprintf(file, "%s\n", arr1[j]);

    for (int j = 0; j < num1; j++)
        printf("%s\n", arr1[j]);
}

void merge(FILE *f1, FILE *f2, FILE *outfile)
{
    char a[100], b[100];
    fscanf(f1, "%s", a);
    fscanf(f2, "%s", b);
    while (1)
    {
        int t;
        if (strcmp(a, b) < 0)
        {
            fprintf(outfile, "%s\n", a);
            t = fscanf(f1, "%s", a);
            if (t == -1)
            {
                fprintf(outfile, "%s\n", b);
                while (fscanf(f2, "%s", b) != EOF)
                    fprintf(outfile, "%s\n", b);
                break;
            }
            continue;
        }
        else if (strcmp(b, a) < 0)
        {
            fprintf(outfile, "%s\n", b);
            t = fscanf(f2, "%s", b);
            if (t == -1)
            {
                fprintf(outfile, "%s\n", a);
                while (fscanf(f1, "%s", a) != EOF)
                    fprintf(outfile, "%s\n", a);
                break;
            }
            continue;
        }
        fprintf(outfile, "%s\n", a);
        fscanf(f1, "%s", a);
        t = fscanf(f1, "%s", a);
        if (t == -1)
        {
            fprintf(outfile, "%s\n", a);
            while (fscanf(f1, "%s", a) != EOF)
                fprintf(outfile, "%s\n", a);
            break;
        }
    }
}
int main(int argc, char *argv[])
{
    mainfile = fopen(argv[1], "r");
    ansfile = fopen(argv[2], "r+");
    while(feof(mainfile) == 0)
    { 
        fseek(ansfile,0,SEEK_SET);
        file1 = fopen("tf1.txt", "w");
        file2 = fopen("tf2.txt", "w");
        filex = fopen("tft.txt", "w");
        filexm = fopen("fxm.txt", "w");
        FILE* tempfile = fopen("tempfile.txt","w");
        sortchunk(file1); // chunks from main file and sorts em to arr1
        sortchunk(file2);
        fclose(file1);
        fclose(file2);
        file1 = fopen("tf1.txt", "r");
        file2 = fopen("tf2.txt", "r");
        merge(file1, file2, tempfile);
        fclose(file1);
        fclose(file2);
        fclose(tempfile);
      //  fclose(ansfile);
        tempfile = fopen("tempfile.txt", "r");
        FILE* tempfiles = fopen("te.txt","w");
        merge(ansfile,tempfile,tempfiles);
        rename("te.txt",argv[2]);
        fclose(tempfiles);
        file1 = fopen("tf1.txt", "w");
        file2 = fopen("tf2.txt", "w");
        sortchunk(file1); // chunks from main file and sorts em to arr1
        sortchunk(file2);
        fclose(file1);
        fclose(file2);
        file1 = fopen("tf1.txt", "r");
        file2 = fopen("tf2.txt", "r");
        merge(file1, file2, filex);
        fclose(file1);
        fclose(file2);
        fclose(filex);
        filex = fopen("tft.txt", "r");
        //fseek(ansfile,0,SEEK_SET);
        merge(filex, ansfile, filexm);
        fclose(filexm);
        fclose(ansfile);
        fclose(filex);
      //  getch();
      //  remove(argv[2]);
        rename("fxm.txt", argv[2]);  // renaming automatically replaces
        printf("renamed\n");
    }
    remove("tf1.txt");
    remove("tf2.txt");
    remove("tft.txt");
    return 0;
}
