#include <stdio.h>
#include <stdlib.h>

#define MAXARRAY_SIZE 200

/*
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
*/

int readArray(int A[])
{
    int size = 0;
    while(scanf("%d", &A[size++]) != EOF);

    return size-1;
}


void printArray(int A[], int size)
{
    printf("=======\n");
    for (int i = 0; i < size; ++i)
    {
        printf("i%d: %d\n", i, A[i]);
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

// Find if key lies in the index range [l, r]
// key == A[l], or key == A[l+1], or ... key == A[r]
// Check key \in [l, r]
int binarySearch(int A[], int key, int l, int r)
{
    int mid = (l + r) / 2;

    if (l > r)
        return -1;

    if (key == A[mid])
        return mid;

    if (key < A[mid])
    {
        // go left [l, mid-1]
        return binarySearch(A, key, l, mid - 1);
    }
    else
    {
        // go right [mid+1, r]
        return binarySearch(A, key, mid+1, r);
    }

}

int main(int argc, char *argv[])
{
    int size, A[MAXARRAY_SIZE];
    int key, index;

    size = readArray(A);

    // Preprocess the array by sorting.
    bubbleSort(A, size);

    printArray(A, size);

    //printf("Enter the number to search for: ");
    //scanf("%d", &key);

    key = atoi(argv[1]);

    // estimate that the key lies in the index range [0, size-1]
    index = binarySearch(A, key, 0, size - 1);

    if (index == -1)
    {
        printf("Sorry: We couldn't find the key %d in the list\n", key);
    }
    else
    {
        printf("Found the key %d at the index %d\n", key, index);
    }
}