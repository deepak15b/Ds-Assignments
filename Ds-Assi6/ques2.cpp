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

struct Node *createCircularList()
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

int main()
{
    struct Node *head = createCircularList();
    if (head == NULL)
        return 0;
    struct Node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("%d\n", head->data);
    return 0;
}
