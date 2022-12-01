#include <stdio.h>
#define MAX_SIZE 10


/*
This function is a way to create an array whose size is unknown.
The scanf() returns the number of inputs it scans.
It then stores it into the l++ index which is post increment.
It increments the index after storing input in the array.
But since it will increment after EOF also, we need to return (l-1).
*/
int readArray(int A[])
{
    int l = 0;

    while (scanf("%d", &A[l++]) != EOF)
    {}
// ctrl + D will make scanf() return EOF to the function.
    return (l-1);
}


void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void bubbleSort(int A[], int l)
{
    int swap_count;

    for (int i = 0; i < (l - 1); i++)
    {
        swap_count = 0;
// Since the last i elements are already sorted.
        for (int j = 0; j < (l - 1 - i); j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                swap_count++;
            }
        }
        if (swap_count <= 0)
        {
            break;
        }
    }
}


/*
The binarySearch function returns the location of key in array A[l.....r].
If key is not found in the array, the function returns -1.
l is the left bound and r is the right bound.
*/
int binarySearch(int A[], int l, int r, int key)
{
    if (l <= r)
    {
        int mid = ((l + r) / 2);

        if (key == A[mid])
        {
            return mid;
        }
        else if (key < A[mid])
        {
            return binarySearch(A, l, (mid - 1), key);
        }
        else
        {
            return binarySearch(A, (mid + 1), r, key);
        }
    }
    else
    {
        return -1;
    }
}


int main()
{
    int arr[MAX_SIZE], size, key;

    printf("Enter the Number to Search for: ");
    scanf("%d", &key);
    printf("Enter the Array Elements:\n");
    size = readArray(arr);

    for (int i = 0; i < 20; i++)
    {
        printf("-");
    }
    printf("\n");

    bubbleSort(arr, size);

    printf("The Sorted Array is:\n");
    for (int i = 0; i < size; i++)
    {
        printf("i%d = %d\n", i, arr[i]);
    }

    int index = binarySearch(arr, 0, (size-1), key);

    if (index == -1)
    {
        printf("Number not found.\n");
    }
    else
    {
        printf("The Index of Number is %d.\n", index);
    }

    return 0;
}
