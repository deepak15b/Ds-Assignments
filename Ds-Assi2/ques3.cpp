// missing no
#include <stdio.h>

#define MAX_SIZE 100

int main()
{
    int numbers[MAX_SIZE];
    int n;
    int i;
    int expectedSum, actualSum = 0;
    int missing;

    printf("Enter value of n (numbers are from 1 to n, one missing): ");
    scanf("%d", &n);

    printf("Enter %d sorted distinct numbers from 1 to %d (one missing):\n", n - 1, n);
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d", &numbers[i]);
    }

    expectedSum = n * (n + 1) / 2;

    for (i = 0; i < n - 1; i++)
    {
        actualSum += numbers[i];
    }

    missing = expectedSum - actualSum;

    printf("Missing number (linear method) = %d\n", missing);

    return 0;
}
