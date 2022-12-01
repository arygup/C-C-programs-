#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct 
{
    int size;
    char*name;
}db ;
db A[5];
int main()
{
    char temp[10];
    for (int i = 0; i < 5; i++)
    {
        scanf("%s", temp);
        scanf("%d", &A[i].size);
        A[i].name = malloc(strlen(temp) + 1);
        strcpy(A[i].name, temp);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%s-->%d\n", A[i].name, A[i].size);
    }
    
}