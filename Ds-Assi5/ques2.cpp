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

int deleteAllKey(struct Node **head, int key)
{
    int count = 0;
    while (*head != NULL && (*head)->data == key)
    {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        count++;
    }
    struct Node *current = *head;
    struct Node *prev = NULL;
    while (current != NULL)
    {
        if (current->data == key)
        {
            struct Node *temp = current;
            prev->next = current->next;
            current = current->next;
            free(temp);
            count++;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
    return count;
}

void displayList(struct Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("Empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("->");
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    int n, value, key;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }
    scanf("%d", &key);
    int count = deleteAllKey(&head, key);
    printf("Count: %d\n", count);
    displayList(head);
    return 0;
}
