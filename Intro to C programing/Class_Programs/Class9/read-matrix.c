#include <stdio.h>

int readMatrix(int A[][4], int norows)  //if the value of columns of the array is not specified it will assume 4.  but we gotta provide rows regardless
{
    for (int i = 0; i < norows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
             scanf("%d", &A[i][j]); 
        }
    }

}

int printMatrix(int A[][4], int norows)
{
     for (int i = 0; i < norows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
             printf("%3d", A[i][j]); 
        }

        printf("\n");
    }
}

int main ()
{
    int A[3][4];

    readMatrix(A, 3);

    //compute matrix

    printMatrix(A, 3);

}