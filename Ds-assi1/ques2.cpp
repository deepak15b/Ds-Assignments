// Remove duplicate elements from an array (keep only unique values)
#include <stdio.h>

#define MAX_SIZE 100

int main()
{
    int numbers[MAX_SIZE];
    int size;
    int i, j, k;

    printf("Enter number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size < 0 || size > MAX_SIZE)
    {
        printf("Invalid size.\n");
        return 0;
    }

    printf("Enter %d elements:\n", size);
    for (i = 0; i < size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Remove duplicates (unsorted array)
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (numbers[i] == numbers[j])
            {
                // shift left
                for (k = j; k < size - 1; k++)
                {
                    numbers[k] = numbers[k + 1];
                }
                size--;
                j--; // recheck the new element at position j
            }
        }
    }

    printf("Array after removing duplicates:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
