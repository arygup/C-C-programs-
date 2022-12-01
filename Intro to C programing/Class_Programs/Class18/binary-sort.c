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

void printArray(int A[], int size)
{
    printf("=====\n");

    for (int i = 0; i < size; i++)
    {
        printf("%d\n", A[i]);
    }
    printf("=====\n");
}
//finding if key lies in the index range [l,r]  
int binarySearch(int A[], int key, int l, int r)
{
    int mid = (l+r)/2;
    if (l>r) // element not found if starting index is greater than ending
    {
        return -1;
    }
    if (key == A[mid])
    {
        return mid; //returning the index where key is present
    }
    if (key < A[mid])
    {
        // go left
        return binarySearch( A, key, l, mid -1);   // if the index is [0,1] mid = 0 and mid -1 = -1. thats why we include the l>r case.
    }
    else
    {
        // go right
        return binarySearch(A, key, mid +1, r);   // if index is [0,2] mid = 1 and mid + 1 = 2 again so [2,2] and it'll keep repeating. hence we include the r<l case. same as above.
    }
}

int main()
{
    int size, A[MAXARRAY_SIZE];
    int key;
    int index;

    size = readArray(A);

    // preprocessing the array
    bubbleSort(A, size);

    printArray(A, size); //printing the sorted array

    printf("Enter the number to search for:");
    scanf("%d", &key);

    index = binarySearch(A, key, 0, size-1); //estimates that the key lies between index [0,size-1]

    if (index == -1)
    {
        printf("key = %d not found\n",  key);
    }
    else
    {
        printf("key = %d found at index = %d\n", key, index); 
    }


}
