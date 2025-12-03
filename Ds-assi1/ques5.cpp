// sum of every row and eevry collumn
#include <stdio.h>

#define MAX 10

int main()
{
    int rows, cols;
    int matrix[MAX][MAX];
    int i, j;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || cols <= 0 || rows > MAX || cols > MAX)
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

    // Sum of each row
    printf("Sum of each row:\n");
    for (i = 0; i < rows; i++)
    {
        int rowSum = 0;
        for (j = 0; j < cols; j++)
        {
            rowSum += matrix[i][j];
        }
        printf("Row %d sum = %d\n", i, rowSum);
    }

    // Sum of each column
    printf("Sum of each column:\n");
    for (j = 0; j < cols; j++)
    {
        int colSum = 0;
        for (i = 0; i < rows; i++)
        {
            colSum += matrix[i][j];
        }
        printf("Column %d sum = %d\n", j, colSum);
    }

    return 0;
}
