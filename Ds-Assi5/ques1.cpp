#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value)
{
    struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value)
{
    struct Node *newNode = createNode(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
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
    struct Node *temp = head;
    while (temp->next != NULL && temp->next->data != target)
        temp = temp->next;
    if (temp->next == NULL)
        return;
    struct Node *newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfterValue(int value, int target)
{
    struct Node *temp = head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;
    if (temp == NULL)
        return;
    struct Node *newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteFromBeginning()
{
    if (head == NULL)
        return;
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteFromEnd()
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    free(temp->next);
    temp->next = NULL;
}

void deleteValue(int value)
{
    if (head == NULL)
        return;
    if (head->data == value)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL && temp->next->data != value)
        temp = temp->next;
    if (temp->next == NULL)
        return;
    struct Node *delNode = temp->next;
    temp->next = delNode->next;
    free(delNode);
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
        printf("\n1. Insert at beginning\n2. Insert at end\n3. Insert before value\n4. Insert after value\n5. Delete from beginning\n6. Delete from end\n7. Delete specific value\n8. Search value\n9. Display list\n10. Exit\n");
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
            deleteFromBeginning();
        }
        else if (choice == 6)
        {
            deleteFromEnd();
        }
        else if (choice == 7)
        {
            scanf("%d", &value);
            deleteValue(value);
        }
        else if (choice == 8)
        {
            scanf("%d", &value);
            searchValue(value);
        }
        else if (choice == 9)
        {
            displayList();
        }
    } while (choice != 10);
    return 0;
}
