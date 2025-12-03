// bubble sort
#include <stdio.h>

int main()
{
    int numbers[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    int i, j, temp;

    printf("Original array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Bubble sort
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
