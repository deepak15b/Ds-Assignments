#include <stdio.h>
#include <string.h>

#define SIZE 100

char q[SIZE];
int front = 0, rear = 0;
int freq[256];

void enqueue(char c)
{
    q[rear++] = c;
}

void dequeue()
{
    front++;
}

int main()
{
    char str[SIZE];
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++)
    {
        freq[str[i]]++;
        enqueue(str[i]);

        while (front < rear && freq[q[front]] > 1)
            dequeue();

        if (front == rear)
            printf("-1 ");
        else
            printf("%c ", q[front]);
    }
}
