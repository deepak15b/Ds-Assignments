#include <stdio.h>

int main()
{
    int a[100], n, i, start = 0, end, j, min, max, temp;
    scanf("%d", &n);
    end = n - 1;
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    while (start < end)
    {
        min = start;
        max = start;
        for (j = start; j <= end; j++)
        {
            if (a[j] < a[min])
                min = j;
            if (a[j] > a[max])
                max = j;
        }

        temp = a[start];
        a[start] = a[min];
        a[min] = temp;

        if (max == start)
            max = min;

        temp = a[end];
        a[end] = a[max];
        a[max] = temp;

        start++;
        end--;
    }

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
