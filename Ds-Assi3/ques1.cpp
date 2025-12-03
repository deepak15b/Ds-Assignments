// menu driven stack
#include <stdio.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

int isFull()
{
    return top == SIZE - 1;
}

int isEmpty()
{
    return top == -1;
}

void push(int value)
{
    if (!isFull())
    {
        top++;
        stack[top] = value;
        printf("Inserted %d\n", value);
    }
    else
    {
        printf("Stack overflow\n");
    }
}

void pop()
{
    if (!isEmpty())
    {
        printf("Deleted %d\n", stack[top]);
        top--;
    }
    else
    {
        printf("Stack underflow\n");
    }
}

void peek()
{
    if (!isEmpty())
        printf("Top element: %d\n", stack[top]);
    else
        printf("Stack is empty\n");
}

void display()
{
    if (isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main()
{
    int choice, value;
    do
    {
        printf("\n1.Push\n2.Pop\n3.isEmpty\n4.isFull\n5.Display\n6.Peek\n7.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf(isEmpty() ? "Stack is empty\n" : "Stack is not empty\n");
            break;
        case 4:
            printf(isFull() ? "Stack is full\n" : "Stack is not full\n");
            break;
        case 5:
            display();
            break;
        case 6:
            peek();
            break;
        case 7:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 7);
    return 0;
}
