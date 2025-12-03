#include <stdio.h>

#define SIZE 100

int main()
{
    int q[SIZE], temp[SIZE];
    int n, i, j = 0, k = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &q[i]);

    for (i = 0; i < n / 2; i++)
    {
        temp[j++] = q[i];
        temp[j++] = q[i + n / 2];
    }

    for (i = 0; i < j; i++)
        printf("%d ", temp[i]);

    return 0;
}
