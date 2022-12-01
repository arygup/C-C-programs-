#include <stdio.h>
#include <stdlib.h>

#define MAXARRAY_SIZE 200

int readArray(int A[])
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > MAXARRAY_SIZE)
    {
        printf("Sorry! cannot store that many elements\n");
        exit(0);
    }

    for (int i = 0; i < size; ++i)
    {
        printf("> ");
        scanf("%d", &A[i]);
    }

    return size;
}

/*
int readArray(int A[])
{
    int size = 0;
    while(scanf("%d", &A[size++]) != EOF);

    return size-1;
}
*/

void printArray(int A[], int size)
{
    printf("=======\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%d\n", A[i]);
    }
    printf("=======\n");
}

void bubbleSort(int A[], int size)
{
    int temp, swap_count = 0;

    if (size == 1)
        return;

    for (int i = 0; i < size - 1; i = i + 1)
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
            ++swap_count;
        }
    }

    if (swap_count > 0)
        bubbleSort(A, size - 1);
}

void loop_bubbleSort(int A[], int size)
{
    int temp, swap_count = 0;

    while (size > 1)
    {
        for (int i = 0; i < size - 1; i = i + 1)
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
                ++swap_count;
            }
        }

        if (swap_count == 0)
            break;
        else
        {
            swap_count = 0;
            size = size - 1;
        }
    }
}

int main()
{
    int size, A[MAXARRAY_SIZE];

    size = readArray(A);

    bubbleSort(A, size);
    printArray(A, size);
}