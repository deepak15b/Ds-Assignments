// concatinate two strings
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main()
{
    char first[MAX_LEN];
    char second[MAX_LEN];
    int i, j;

    printf("Enter first string: ");
    scanf("%s", first);

    printf("Enter second string: ");
    scanf("%s", second);

    // Manual concatenation: first = first + second
    i = 0;
    while (first[i] != '\0')
    {
        i++;
    }

    j = 0;
    while (second[j] != '\0')
    {
        first[i] = second[j];
        i++;
        j++;
    }

    first[i] = '\0';

    printf("Concatenated string: %s\n", first);

    return 0;
}
