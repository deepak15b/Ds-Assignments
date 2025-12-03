#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node **head, int value)
{
    struct Node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

struct Node *reverseList(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *nextNode;
    while (current != NULL)
    {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

void displayList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("->");
        temp = temp->next;
    }
    printf("->NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int n, value;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }
    head = reverseList(head);
    displayList(head);
    return 0;
}
