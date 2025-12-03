// sparse matrix
#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define MAX_TERMS 100

typedef struct
{
    int row;
    int col;
    int value;
} Term;

void tripletToFull(Term t[], int full[MAX_ROWS][MAX_COLS])
{
    int rows = t[0].row;
    int cols = t[0].col;
    int i, r, c;

    for (r = 0; r < rows; r++)
    {
        for (c = 0; c < cols; c++)
        {
            full[r][c] = 0;
        }
    }

    for (i = 1; i <= t[0].value; i++)
    {
        full[t[i].row][t[i].col] = t[i].value;
    }
}

int fullToTriplet(int full[MAX_ROWS][MAX_COLS], int rows, int cols, Term t[])
{
    int i, j;
    int k = 1;

    t[0].row = rows;
    t[0].col = cols;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (full[i][j] != 0)
            {
                t[k].row = i;
                t[k].col = j;
                t[k].value = full[i][j];
                k++;
            }
        }
    }

    t[0].value = k - 1;
    return k;
}

void printTriplet(Term t[])
{
    int i;
    printf("Row  Col  Value\n");
    for (i = 0; i <= t[0].value; i++)
    {
        printf("%3d  %3d  %3d\n", t[i].row, t[i].col, t[i].value);
    }
}

int main()
{
    Term A[MAX_TERMS], B[MAX_TERMS], C[MAX_TERMS];
    int fullA[MAX_ROWS][MAX_COLS];
    int fullB[MAX_ROWS][MAX_COLS];
    int fullC[MAX_ROWS][MAX_COLS];
    int i, j, k;
    int rowsA, colsA, nonZeroA;
    int rowsB, colsB, nonZeroB;
    int choice;

    // Input matrix A in triplet form
    printf("Enter rows, cols and number of non-zero elements of matrix A: ");
    scanf("%d %d %d", &rowsA, &colsA, &nonZeroA);
    A[0].row = rowsA;
    A[0].col = colsA;
    A[0].value = nonZeroA;

    printf("Enter triplets (row col value) for A:\n");
    for (i = 1; i <= nonZeroA; i++)
    {
        scanf("%d %d %d", &A[i].row, &A[i].col, &A[i].value);
    }

    printf("\nMatrix A (triplet form):\n");
    printTriplet(A);

    printf("\n1. Transpose\n2. Addition (A + B)\n3. Multiplication (A * B)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        // (a) Transpose: easy in triplet
        Term T[MAX_TERMS];
        int num = A[0].value;
        int cols = A[0].col;
        int rowCount[MAX_COLS];
        int index[MAX_COLS];

        // fast transpose
        T[0].row = A[0].col;
        T[0].col = A[0].row;
        T[0].value = num;

        for (i = 0; i < cols; i++)
            rowCount[i] = 0;

        for (i = 1; i <= num; i++)
            rowCount[A[i].col]++;

        index[0] = 1;
        for (i = 1; i < cols; i++)
            index[i] = index[i - 1] + rowCount[i - 1];

        for (i = 1; i <= num; i++)
        {
            int col = A[i].col;
            int pos = index[col];
            index[col]++;
            T[pos].row = A[i].col;
            T[pos].col = A[i].row;
            T[pos].value = A[i].value;
        }

        printf("\nTranspose of A (triplet form):\n");
        printTriplet(T);
    }
    else if (choice == 2)
    {
        // (b) Addition A + B
        printf("Enter rows, cols and number of non-zero elements of matrix B: ");
        scanf("%d %d %d", &rowsB, &colsB, &nonZeroB);
        B[0].row = rowsB;
        B[0].col = colsB;
        B[0].value = nonZeroB;

        printf("Enter triplets (row col value) for B:\n");
        for (i = 1; i <= nonZeroB; i++)
        {
            scanf("%d %d %d", &B[i].row, &B[i].col, &B[i].value);
        }

        if (rowsA != rowsB || colsA != colsB)
        {
            printf("Addition not possible, dimensions do not match.\n");
            return 0;
        }

        tripletToFull(A, fullA);
        tripletToFull(B, fullB);

        for (i = 0; i < rowsA; i++)
        {
            for (j = 0; j < colsA; j++)
            {
                fullC[i][j] = fullA[i][j] + fullB[i][j];
            }
        }

        fullToTriplet(fullC, rowsA, colsA, C);

        printf("\nResult of A + B in triplet form:\n");
        printTriplet(C);
    }
    else if (choice == 3)
    {
        // (c) Multiplication A * B
        printf("Enter rows, cols and number of non-zero elements of matrix B: ");
        scanf("%d %d %d", &rowsB, &colsB, &nonZeroB);
        B[0].row = rowsB;
        B[0].col = colsB;
        B[0].value = nonZeroB;

        printf("Enter triplets (row col value) for B:\n");
        for (i = 1; i <= nonZeroB; i++)
        {
            scanf("%d %d %d", &B[i].row, &B[i].col, &B[i].value);
        }

        if (colsA != rowsB)
        {
            printf("Multiplication not possible (cols of A != rows of B).\n");
            return 0;
        }

        tripletToFull(A, fullA);
        tripletToFull(B, fullB);

        // Multiply: fullC = fullA * fullB
        for (i = 0; i < rowsA; i++)
        {
            for (j = 0; j < colsB; j++)
            {
                fullC[i][j] = 0;
                for (k = 0; k < colsA; k++)
                {
                    fullC[i][j] += fullA[i][k] * fullB[k][j];
                }
            }
        }

        fullToTriplet(fullC, rowsA, colsB, C);

        printf("\nResult of A * B in triplet form:\n");
        printTriplet(C);
    }
    else
    {
        printf("Invalid choice.\n");
    }

    return 0;
}
