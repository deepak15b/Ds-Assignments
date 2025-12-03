// transpose matrix
#include <stdio.h>

#define MAX 10

int main()
{
    int rows, cols;
    int i, j;
    int matrix[MAX][MAX];
    int transpose[MAX][MAX];

    printf("Enter number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    if (rows > MAX || cols > MAX || rows <= 0 || cols <= 0)
    {
        printf("Invalid size.\n");
        return 0;
    }

    printf("Enter elements of the matrix (%d x %d):\n", rows, cols);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Compute transpose
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("Transpose of the matrix (%d x %d):\n", cols, rows);
    for (i = 0; i < cols; i++)
    {
        for (j = 0; j < rows; j++)
        {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
