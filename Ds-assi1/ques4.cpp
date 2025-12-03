// reverse string
#include <stdio.h>

#define MAX_SIZE 100

int main()
{
    int numbers[MAX_SIZE];
    int size;
    int i, temp;

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

    // Reverse the array in-place
    for (i = 0; i < size / 2; i++)
    {
        temp = numbers[i];
        numbers[i] = numbers[size - 1 - i];
        numbers[size - 1 - i] = temp;
    }

    printf("Reversed array:\n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
