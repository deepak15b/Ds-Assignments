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

struct Node *createList(int isCircular)
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
    if (isCircular && temp != NULL)
        temp->next = head;
    return head;
}

int isCircularList(struct Node *head)
{
    if (head == NULL)
        return 0;
    struct Node *slow = head;
    struct Node *fast = head->next;
    while (fast != NULL && fast->next != NULL)
    {
        if (slow == fast)
            return 1;
        slow = slow->next;
        fast = fast->next->next;
    }
    return 0;
}

int main()
{
    int flag;
    scanf("%d", &flag);
    struct Node *head = createList(flag);
    if (isCircularList(head))
        printf("True\n");
    else
        printf("False\n");
    return 0;
}
