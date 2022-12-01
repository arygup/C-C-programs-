#include <stdio.h>
#define NOSTUDENTS 5

int readmarks(int A[], int size)
{
    // read array
    for (int i = 0; i < size; i++)
    {
        scanf("%f", &A[i]);
    }
}


int main()
{
    float marks[NOSTUDENTS], sum=0;

    readmarks(marks, NOSTUDENTS);

    for (int j = 0; j < NOSTUDENTS; j++)
    {
        sum = sum + marks[j];
    }

    printf("%3f/n", sum/NOSTUDENTS);
}