// no of inversion
#include <stdio.h>

#define MAX_SIZE 100

int main()
{
    int numbers[MAX_SIZE];
    int n;
    int i, j;
    int inversionCount = 0;

    printf("Enter number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (numbers[i] > numbers[j])
            {
                inversionCount++;
            }
        }
    }

    printf("Total number of inversions = %d\n", inversionCount);

    return 0;
}
