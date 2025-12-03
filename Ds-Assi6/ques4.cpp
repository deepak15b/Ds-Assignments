#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char ch;
    struct Node *prev;
    struct Node *next;
};

struct Node *createNode(char c)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->ch = c;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

struct Node *createListFromString(char s[])
{
    struct Node *head = NULL, *temp = NULL;
    for (int i = 0; s[i] != '\0'; i++)
    {
        struct Node *node = createNode(s[i]);
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

int isPalindrome(struct Node *head)
{
    if (head == NULL)
        return 1;
    struct Node *left = head;
    struct Node *right = head;
    while (right->next != NULL)
        right = right->next;
    while (left != right && right->next != left)
    {
        if (left->ch != right->ch)
            return 0;
        left = left->next;
        right = right->prev;
    }
    return 1;
}

int main()
{
    char s[100];
    scanf("%s", s);
    struct Node *head = createListFromString(s);
    if (isPalindrome(head))
        printf("True\n");
    else
        printf("False\n");
    return 0;
}
