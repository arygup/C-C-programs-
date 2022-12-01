#include <stdio.h>
#include <stdlib.h>
#define MAXARRAY_SIZE 200

int readArray(int A[])
{
    int size;

    printf("Enter Array size: ");
    scanf("%d", &size);

    if (size > MAXARRAY_SIZE)
    {
        printf("too big\n");
        exit(0);
    }

    for (int i = 0; i < size; i++)
    {
        printf("> ");
        scanf("%d", &A[i]);
    }
    return size;
}

/*int readArray( int A[])
{
    int size = 0;
    while (scanf("%d", &A[size++]) != EOF);
    return size -1;

}
*/

void printArray(int A[], int size)
{
    printf("=====\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d\n", A[i]);
    }
    printf("=====\n");
}

void bubbleSort(int A[], int size)
{
    int temp;

    while (size > 1)
    {
        for (int i = 0; i < size; i++)
        {
            if (A[i] < A[i + 1])
            {
                continue;
            }
            else
            {
                temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
            }
        }
        size--;
    }
}

int main()
{
    int size, A[MAXARRAY_SIZE];

    size = readArray(A);

    bubbleSort(A, size);

    printArray(A, size);
}
