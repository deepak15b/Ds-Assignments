// convert upper to lower
#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch);

    if (ch >= 'A' && ch <= 'Z')
    {
        ch = ch + ('a' - 'A'); // or: ch = tolower(ch);
        printf("Lowercase character: %c\n", ch);
    }
    else
    {
        printf("Character is already lowercase or not a letter: %c\n", ch);
    }

    return 0;
}
