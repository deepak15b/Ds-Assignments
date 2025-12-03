#include <stdio.h>

#define MAX_SIZE 10
#define MAX_STORE 200

int main()
{
    int n; // order of square matrix
    int i, j;

    printf("Enter order n of square matrix (n x n): ");
    scanf("%d", &n);

    // (a) Diagonal Matrix: only n elements
    int diag[MAX_SIZE][MAX_SIZE];
    int diagStore[MAX_SIZE];

    printf("\nEnter diagonal matrix elements (only diagonal, rest assumed 0):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            diag[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("Element (%d,%d): ", i, i);
        scanf("%d", &diag[i][i]);
        diagStore[i] = diag[i][i]; // store only diagonal
    }

    printf("Diagonal matrix from compact storage:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                printf("%d ", diagStore[i]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

    // (b) Tri-diagonal Matrix: 3n - 2 elements
    int tri[MAX_SIZE][MAX_SIZE];
    int triStore[3 * MAX_SIZE];
    int index = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            tri[i][j] = 0;
        }
    }

    printf("\nEnter tri-diagonal matrix (only main, upper, lower diagonals):\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j || i == j + 1 || i + 1 == j)
            {
                printf("Element (%d,%d): ", i, j);
                scanf("%d", &tri[i][j]);
            }
        }
    }

    // compact store
    index = 0;
    for (i = 0; i < n; i++)
    {
        if (i > 0)
        { // lower diagonal
            triStore[index++] = tri[i][i - 1];
        }
        triStore[index++] = tri[i][i]; // main diagonal
        if (i < n - 1)
        { // upper diagonal
            triStore[index++] = tri[i][i + 1];
        }
    }

    printf("Tri-diagonal matrix from compact storage:\n");
    index = 0;
    for (i = 0; i < n; i++)
    {
        int lower = (i > 0) ? triStore[index] : 0;
        if (i > 0)
            index++;
        int mainDiag = triStore[index++];
        int upper = (i < n - 1) ? triStore[index] : 0;
        if (i < n - 1)
            index++;

        for (j = 0; j < n; j++)
        {
            if (j == i - 1)
                printf("%d ", lower);
            else if (j == i)
                printf("%d ", mainDiag);
            else if (j == i + 1)
                printf("%d ", upper);
            else
                printf("0 ");
        }
        printf("\n");
    }

    // (c) Lower triangular, (d) Upper triangular, (e) Symmetric
    // Idea: store only needed elements in 1D:
    // Lower: i>=j, count = n*(n+1)/2
    // Upper: i<=j, count = n*(n+1)/2
    // Symmetric: store either upper or lower triangle, count = n*(n+1)/2

    printf("\nFor lower/upper/symmetric matrices, use formula:\n");
    printf("1D index for lower triangle (i>=j): index = i*(i+1)/2 + j\n");
    printf("1D index for upper triangle (i<=j): index = j*(j+1)/2 + i\n");

    return 0;
}
