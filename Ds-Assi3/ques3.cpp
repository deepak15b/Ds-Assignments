// check balance
#include <stdio.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int main()
{
    char exp[SIZE];
    printf("Enter expression: ");
    scanf("%s", exp);

    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == -1)
            {
                printf("Not Balanced");
                return 0;
            }
            char temp = pop();
            if ((exp[i] == ')' && temp != '(') ||
                (exp[i] == '}' && temp != '{') ||
                (exp[i] == ']' && temp != '['))
            {
                printf("Not Balanced");
                return 0;
            }
        }
    }
    printf(top == -1 ? "Balanced" : "Not Balanced");
    return 0;
}
