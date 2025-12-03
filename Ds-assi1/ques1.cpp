// Menu-driven program for array operations
#include <stdio.h>

#define MAX_SIZE 100

int main()
{
    int numbers[MAX_SIZE];
    int size = 0; // current number of elements
    int choice;

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. CREATE\n");
        printf("2. DISPLAY\n");
        printf("3. INSERT\n");
        printf("4. DELETE\n");
        printf("5. LINEAR SEARCH\n");
        printf("6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int i;
            printf("Enter number of elements (max %d): ", MAX_SIZE);
            scanf("%d", &size);

            if (size < 0 || size > MAX_SIZE)
            {
                printf("Invalid size! Setting size to 0.\n");
                size = 0;
            }
            else
            {
                printf("Enter %d elements:\n", size);
                for (i = 0; i < size; i++)
                {
                    printf("Element %d: ", i + 1);
                    scanf("%d", &numbers[i]);
                }
            }
        }
        else if (choice == 2)
        {
            int i;
            if (size == 0)
            {
                printf("Array is empty.\n");
            }
            else
            {
                printf("Array elements are: ");
                for (i = 0; i < size; i++)
                {
                    printf("%d ", numbers[i]);
                }
                printf("\n");
            }
        }
        else if (choice == 3)
        {
            int newValue, position, i;

            if (size == MAX_SIZE)
            {
                printf("Array is full. Cannot insert.\n");
            }
            else
            {
                printf("Enter the value to insert: ");
                scanf("%d", &newValue);
                printf("Enter the position to insert (1 to %d): ", size + 1);
                scanf("%d", &position);

                if (position < 1 || position > size + 1)
                {
                    printf("Invalid position.\n");
                }
                else
                {
                    // shift elements to the right
                    for (i = size - 1; i >= position - 1; i--)
                    {
                        numbers[i + 1] = numbers[i];
                    }
                    numbers[position - 1] = newValue;
                    size++;
                    printf("Value inserted.\n");
                }
            }
        }
        else if (choice == 4)
        {
            int position, i;
            if (size == 0)
            {
                printf("Array is empty. Nothing to delete.\n");
            }
            else
            {
                printf("Enter the position to delete (1 to %d): ", size);
                scanf("%d", &position);

                if (position < 1 || position > size)
                {
                    printf("Invalid position.\n");
                }
                else
                {
                    // shift elements to the left
                    for (i = position - 1; i < size - 1; i++)
                    {
                        numbers[i] = numbers[i + 1];
                    }
                    size--;
                    printf("Element deleted.\n");
                }
            }
        }
        else if (choice == 5)
        {
            int key, i;
            int found = 0;

            if (size == 0)
            {
                printf("Array is empty.\n");
            }
            else
            {
                printf("Enter value to search: ");
                scanf("%d", &key);

                for (i = 0; i < size; i++)
                {
                    if (numbers[i] == key)
                    {
                        printf("Value found at position %d.\n", i + 1);
                        found = 1;
                        break;
                    }
                }

                if (!found)
                {
                    printf("Value not found in the array.\n");
                }
            }
        }
        else if (choice == 6)
        {
            printf("Exiting program.\n");
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
