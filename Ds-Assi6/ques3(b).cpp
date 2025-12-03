#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

struct Node *createCircular()
{
    int n, value;
    struct Node *head = NULL, *temp = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        struct Node *node = createNode(value);
        if (head == NULL)
        {
            head = node;
            temp = node;
        }
        else
        {
            temp->next = node;
            temp = node;
        }
    }
    if (temp != NULL)
        temp->next = head;
    return head;
}

int sizeOfCircular(struct Node *head)
{
    if (head == NULL)
        return 0;
    int count = 0;
    struct Node *temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main()
{
    struct Node *head = createCircular();
    printf("%d\n", sizeOfCircular(head));
    return 0;
}
