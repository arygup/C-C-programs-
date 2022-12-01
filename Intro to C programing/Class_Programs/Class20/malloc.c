#include <stdio.h> // the one with malloc
#include <stdlib.h>
#include <string.h>

#define MAXNAME_LEN 20
#define MAXNONAMES 100

int readNames(char *names[])
{
    int nonames = 0;
    char tempname[MAXNAME_LEN];
    while(scanf("%s", tempname) != EOF){   //taking input to tempname
        names[nonames] = (char *)malloc(strlen(tempname)+1);
        strcpy(names[nonames], tempname);
        nonames++;
    }   
    return nonames; //returning length of array //(char *)
}

void printArray(char *names[], int nonames)
{
    printf("=======\n");
    for (int i = 0; i < nonames; ++i)
    {
        printf("%s\n", names[i]); 
    }
    printf("=======\n");
}

void bubbleSort(char *names[], int nonames)
{
    int swap_count = 0;
    char *tempstr; //tempstr is a character pointer. 
    //means its just a pointer => pointing towards something
    // which is a character. or base address of a string.

    if (nonames == 1)
        return;

    for (int i = 0; i < nonames - 1; i = i + 1)
    {
        if (strcmp(names[i], names[i+1]) < 0)
        {
            continue;
        }
        else 
        {
            swap_count++;
            //try writing your own swap function for the following:
            //swap( , );  
            tempstr = names[i];
            names[i] = names[i+1];
            names[i+1] = tempstr;
        }
    }

    if (swap_count > 0)
        bubbleSort(names, nonames - 1);
}

int main()
{
    int nonames;
    char *names[MAXNONAMES]; //array of character pointers

    nonames = readNames(names);

    bubbleSort(names, nonames);

    printArray(names, nonames);
}





//this one takes 100 names each 
//having their own length as in:
//(no extra space wasted to store
//each name as 20 characters long)
//sorts them
//prints them