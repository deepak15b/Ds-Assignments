// stack using one queue
#include <stdio.h>

#define SIZE 100

int q[SIZE];
int front = 0, rear = 0;

void push(int x)
{
    int size = rear - front;
    q[rear++] = x;
    for (int i = 0; i < size; i++)
        q[rear++] = q[front++];
}

int pop()
{
    if (front == rear)
        return -1;
    return q[front++];
}

int main()
{
    push(10);
    push(20);
    push(30);
    printf("%d ", pop());
    printf("%d ", pop());
}
