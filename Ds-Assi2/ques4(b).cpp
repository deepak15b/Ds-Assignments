// reverse a string
#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main()
{
    char text[MAX_LEN];
    int i, j;
    char temp;

    printf("Enter a string (no spaces): ");
    scanf("%s", text);

    i = 0;
    j = strlen(text) - 1;

    while (i < j)
    {
        temp = text[i];
        text[i] = text[j];
        text[j] = temp;
        i++;
        j--;
    }

    printf("Reversed string: %s\n", text);

    return 0;
}
