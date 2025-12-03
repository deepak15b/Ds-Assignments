// matrix multipliction
#include <stdio.h>

#define MAX 10

int main()
{
    int rowsA, colsA, rowsB, colsB;
    int i, j, k;

    int matrixA[MAX][MAX];
    int matrixB[MAX][MAX];
    int result[MAX][MAX];

    printf("Enter rows and columns of first matrix (A): ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter rows and columns of second matrix (B): ");
    scanf("%d %d", &rowsB, &colsB);

    if (colsA != rowsB)
    {
        printf("Matrix multiplication not possible (cols of A must equal rows of B).\n");
        return 0;
    }

    if (rowsA > MAX || colsA > MAX || rowsB > MAX || colsB > MAX)
    {
        printf("Matrix size too large.\n");
        return 0;
    }

    printf("Enter elements of matrix A (%d x %d):\n", rowsA, colsA);
    for (i = 0; i < rowsA; i++)
    {
        for (j = 0; j < colsA; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter elements of matrix B (%d x %d):\n", rowsB, colsB);
    for (i = 0; i < rowsB; i++)
    {
        for (j = 0; j < colsB; j++)
        {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Initialize result matrix to 0
    for (i = 0; i < rowsA; i++)
    {
        for (j = 0; j < colsB; j++)
        {
            result[i][j] = 0;
        }
    }

    // Matrix multiplication
    for (i = 0; i < rowsA; i++)
    {
        for (j = 0; j < colsB; j++)
        {
            for (k = 0; k < colsA; k++)
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    printf("Resultant matrix (A x B):\n");
    for (i = 0; i < rowsA; i++)
    {
        for (j = 0; j < colsB; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
