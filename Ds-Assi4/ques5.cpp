// stack using two queue
#include <stdio.h>

#define SIZE 100

int q1[SIZE], q2[SIZE];
int f1 = 0, r1 = 0, f2 = 0, r2 = 0;

void push(int x)
{
    q2[r2++] = x;
    while (f1 != r1)
        q2[r2++] = q1[f1++];
    int t;
    t = f1;
    f1 = f2;
    f2 = t;
    t = r1;
    r1 = r2;
    r2 = t;
}

int pop()
{
    if (f1 == r1)
        return -1;
    return q1[f1++];
}

int main()
{
    push(10);
    push(20);
    push(30);
    printf("%d ", pop());
    printf("%d ", pop());
}
