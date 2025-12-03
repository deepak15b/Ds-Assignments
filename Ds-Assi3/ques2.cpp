// reverse sting
#include <stdio.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c)
{
    if (top < SIZE - 1)
        stack[++top] = c;
}

char pop()
{
    if (top >= 0)
        return stack[top--];
    return '\0';
}

int main()
{
    char str[SIZE];
    printf("Enter string: ");
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++)
        push(str[i]);
    printf("Reversed: ");
    while (top != -1)
        printf("%c", pop());
    return 0;
}
