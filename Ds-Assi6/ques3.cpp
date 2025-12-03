#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

struct Node *createList()
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
            node->prev = temp;
            temp = node;
        }
    }
    return head;
}

int sizeOfDoubly(struct Node *head)
{
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    struct Node *head = createList();
    printf("%d\n", sizeOfDoubly(head));
    return 0;
}
