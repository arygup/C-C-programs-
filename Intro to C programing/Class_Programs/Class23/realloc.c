#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_ESTIMATE 50
#define INCREMENTAL_SIZE 25
#define MAX_NAME_SIZE 30

char **names; //global variables can be used in all sorts of functions.

int readNames()
{
    int nonames = 0;
    int currentMaxSize = INIT_ESTIMATE;
    char tempstr[MAX_NAME_SIZE];

    names = (char**)malloc(INIT_ESTIMATE*sizeof(char*));
    //i got memomory in heap which can store 50 character pointers.
    
        while (scanf("%s", tempstr) != EOF){
            if (nonames >= currentMaxSize)
            {
                currentMaxSize += INCREMENTAL_SIZE; 
                names = (char**)realloc(names, currentMaxSize*sizeof(char*));
                // if i feel like storing more names, realloc will give me more memory
                // to store pointers at
            }

            names[nonames] = (char *)malloc(strlen(tempstr) + 1);
            strcpy(names[nonames], tempstr);
            nonames++;
            //or could do : strcpy(names[nonames++], tempstr); and return nonames only.
        }
        
    return nonames;
}

void printArray(int nonames)
{
    printf("=======\n");
    for (int i = 0; i < nonames; i++)
    {
        printf("%s\n", names[i]);
    }
    printf("=======\n");
}

void bubbleSort(int nonames)
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
        bubbleSort(nonames - 1);
}

int main()
{
    int nonames;

    nonames = readNames();

    bubbleSort(nonames);

    printArray(nonames);

    //printArray(readNames());
}

//this one initially can afford 50 names 
//of variable length each (like malloc)
//but if u want more names u can extend
//sorts them
//prints them