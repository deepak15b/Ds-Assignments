#include <stdio.h>

void merge(int a[], int l, int m, int r)
{
    int b[100], i = l, j = m + 1, k = l;
    while (i <= m && j <= r)
        b[k++] = a[i] < a[j] ? a[i++] : a[j++];
    while (i <= m)
        b[k++] = a[i++];
    while (j <= r)
        b[k++] = a[j++];
    for (i = l; i <= r; i++)
        a[i] = b[i];
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int a[100], n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    mergeSort(a, 0, n - 1);
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}
