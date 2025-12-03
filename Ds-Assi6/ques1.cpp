#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

void insertAtBeginning(int value)
{
    struct Node *node = createNode(value);
    if (head == NULL)
    {
        head = node;
        return;
    }
    node->next = head;
    head->prev = node;
    head = node;
}

void insertAtEnd(int value)
{
    struct Node *node = createNode(value);
    if (head == NULL)
    {
        head = node;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = node;
    node->prev = temp;
}

void insertBeforeValue(int value, int target)
{
    if (head == NULL)
        return;
    if (head->data == target)
    {
        insertAtBeginning(value);
        return;
    }
    struct Node *temp = head->next;
    while (temp != NULL && temp->data != target)
        temp = temp->next;
    if (temp == NULL)
        return;
    struct Node *node = createNode(value);
    node->next = temp;
    node->prev = temp->prev;
    temp->prev->next = node;
    temp->prev = node;
}

void insertAfterValue(int value, int target)
{
    struct Node *temp = head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;
    if (temp == NULL)
        return;
    struct Node *node = createNode(value);
    node->next = temp->next;
    node->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = node;
    temp->next = node;
}

void deleteValue(int value)
{
    if (head == NULL)
        return;
    struct Node *temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    if (temp == NULL)
        return;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
}

void searchValue(int value)
{
    struct Node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Not found\n");
}

void displayList()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, value, target;
    do
    {
        printf("\n1.Insert at beginning\n2.Insert at end\n3.Insert before value\n4.Insert after value\n5.Delete value\n6.Search\n7.Display\n8.Exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            scanf("%d", &value);
            insertAtBeginning(value);
        }
        else if (choice == 2)
        {
            scanf("%d", &value);
            insertAtEnd(value);
        }
        else if (choice == 3)
        {
            scanf("%d %d", &value, &target);
            insertBeforeValue(value, target);
        }
        else if (choice == 4)
        {
            scanf("%d %d", &value, &target);
            insertAfterValue(value, target);
        }
        else if (choice == 5)
        {
            scanf("%d", &value);
            deleteValue(value);
        }
        else if (choice == 6)
        {
            scanf("%d", &value);
            searchValue(value);
        }
        else if (choice == 7)
        {
            displayList();
        }
    } while (choice != 8);
    return 0;
}
