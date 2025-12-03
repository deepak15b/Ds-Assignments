// circular queue
#include <stdio.h>

#define SIZE 100

int cq[SIZE];
int front = -1, rear = -1;

int isFull()
{
    return (rear + 1) % SIZE == front;
}

int isEmpty()
{
    return front == -1;
}

void enqueue(int value)
{
    if (!isFull())
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % SIZE;
        cq[rear] = value;
        printf("Inserted %d\n", value);
    }
    else
    {
        printf("Queue Full\n");
    }
}

void dequeue()
{
    if (!isEmpty())
    {
        printf("Deleted %d\n", cq[front]);
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
    else
    {
        printf("Queue Empty\n");
    }
}

void peek()
{
    if (!isEmpty())
        printf("Front: %d\n", cq[front]);
    else
        printf("Queue Empty\n");
}

void display()
{
    if (isEmpty())
    {
        printf("Queue Empty\n");
    }
    else
    {
        int i = front;
        while (1)
        {
            printf("%d ", cq[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;
    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.isEmpty\n4.isFull\n5.Display\n6.Peek\n7.Exit\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            scanf("%d", &value);
            enqueue(value);
        }
        else if (choice == 2)
            dequeue();
        else if (choice == 3)
            printf(isEmpty() ? "Empty\n" : "Not Empty\n");
        else if (choice == 4)
            printf(isFull() ? "Full\n" : "Not Full\n");
        else if (choice == 5)
            display();
        else if (choice == 6)
            peek();
    } while (choice != 7);
}
