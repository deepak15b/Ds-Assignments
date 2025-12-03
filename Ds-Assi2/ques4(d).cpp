// sort string alpha
#include <stdio.h>
#include <string.h>

#define MAX_STRINGS 50
#define MAX_LEN 50

int main()
{
    char words[MAX_STRINGS][MAX_LEN];
    int n;
    int i, j;
    char temp[MAX_LEN];

    printf("How many strings? ");
    scanf("%d", &n);

    printf("Enter %d strings (no spaces):\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%s", words[i]);
    }

    // Bubble sort on strings
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(words[j], words[j + 1]) > 0)
            {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    printf("Strings in alphabetical order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", words[i]);
    }

    return 0;
}
