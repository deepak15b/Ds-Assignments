// binary search
#include <stdio.h>

#define MAX_SIZE 100

int main()
{
    int numbers[MAX_SIZE];
    int n;
    int key;
    int low, high, mid;
    int i;
    int found = 0;

    printf("Enter number of elements (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    printf("Enter %d elements in **sorted** order:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    printf("Enter value to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (numbers[mid] == key)
        {
            printf("Element found at position %d (index %d).\n", mid + 1, mid);
            found = 1;
            break;
        }
        else if (numbers[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (!found)
    {
        printf("Element not found in the array.\n");
    }

    return 0;
}
