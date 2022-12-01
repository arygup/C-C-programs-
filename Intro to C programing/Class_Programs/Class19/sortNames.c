#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAME_LEN 20
#define MAXNONAMES 100

int readNames(char names[][MAXNAME_LEN])
{
    int nonames = 0;
    while(scanf("%s", &names[nonames++][0]) != EOF);   //taking input to matrix => rowise

    // while(scanf("%s", &names[nonames][0]) != EOF){     //both statements work the same way.
    //     nonames++;
    //} but YOU RETURN NONAMES IN THIS CASE. NOT NONAMES -1 like in the first one.

    return nonames-1; //returning number of rows of matrix
}

void printArray(char names[][MAXNAME_LEN], int nonames)
{
    printf("=======\n");
    for (int i = 0; i < nonames; ++i)
    {
        printf("%s\n", &names[i][0]);
    }
    printf("=======\n");
}

void bubbleSort(char names[][MAXNAME_LEN], int nonames)
{
    int swap_count = 0;
    char tempstr[MAXNAME_LEN]; //tempstr contains the base address apparently

    if (nonames == 1)
        return;

    for (int i = 0; i < nonames-1; i = i + 1)
    {
        if (strcmp(&names[i][0], &names[i+1][0]) < 0)
        {
            continue;
        }
        else
        {
            swap_count++;

            strcpy(tempstr, &names[i][0]);
            strcpy(&names[i][0], &names[i+1][0]);
            strcpy(&names[i+1][0], tempstr);
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

    bubbleSort(names, nonames);

    printArray(names, nonames);

}




//this one takes upto 100 names 
//each 20 letter long
//sorts them
//prints them