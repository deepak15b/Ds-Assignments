#include <stdio.h>
#include <ctype.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}

void push(char c) { stack[++top] = c; }

char pop() { return stack[top--]; }

int main()
{
    char infix[SIZE], postfix[SIZE];
    int j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (int i = 0; infix[i] != '\0'; i++)
    {
        if (isalnum(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
                postfix[j++] = pop();
            pop();
        }
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = pop();
            push(infix[i]);
        }
    }
    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
    printf("Postfix: %s", postfix);
    return 0;
}
