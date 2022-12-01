//this is an incomplete and a wrong code.

#include <stdio.h>
#include <stdlib.h>

#define MAXNAME_LEN 20
#define MAXNONAMES 100

int readNames(char names[][MAXNAME_LEN])
{
    int nonames = 0;
    while(scanf("%s", &names[nonames++]) != EOF);   //taking input to array

    return nonames-1; //returning length pf array
}

void printArray(char names[][MAXNAME_LEN], int nonames)
{
    printf("=======\n");
    for (int i = 0; i < nonames; ++i)
    {
        printf("%s\n", names[i]);
    }
    printf("=======\n");
}

void bubbleSort(int names[][MAXNAME_LEN], int nonames)
{
    int swap_count = 0;
    char tempstr;

    if (nonames == 1)
        return;

    for (int i = 0; i < nonames - 1; i = i + 1)
    {
        if (names[i] < names[i + 1])
        {
            continue;
        }
        else
        {
            tempstr = names[i];
            names[i][i] = names[i + 1][i];
            names[i + 1][i] = tempstr;
            ++swap_count;
        }
    }

    if (swap_count > 0)
        bubbleSort(names, nonames - 1);
}


int main()
{
    int nonames;
    char names[MAXNONAMES][MAXNAME_LEN];

    nonames = readNames(names);

    //bubbleSort(names, nonames);
    printArray(names, nonames);
}