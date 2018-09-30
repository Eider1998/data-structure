/*顺序创立链表*/

/*
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;

}*head, *tail;

struct node *creat(int n)
{
    int i;
    struct node *p;

    head = (struct node *)malloc(sizeof(struct node));
    head-> next = NULL;
    tail = head;

    for(i = 0; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p-> next = NULL;
        scanf("%d", &p-> data);
        tail-> next = p;;
        tail = p;
    }

    return head;
}

void print(struct node *head)
{
    struct node *p;

    p = head;

    while(p-> next != NULL)
    {
        p = p-> next;
        printf("%d ", p-> data);
    }

}

int main(void)
{
    int n;
    struct node *h;

    scanf("%d", &n);

    h = creat(n);
    print(h);

    return 0;
}

*/

/*插入元素*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;

}*head, *tail;

struct node *creat(int n)
{
    int i;
    struct node *p;

    head = (struct node *)malloc(sizeof(struct node));
    head-> next = NULL;
    tail = head;

    for(i = 0; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p-> next = NULL;
        scanf("%d", &p-> data);
        tail-> next = p;;
        tail = p;
    }

    return head;
}

struct node *sert(struct node *head, int a)
{
    struct node *p, *q, *x;
    p = head;
    q = p;

    x = (struct node *)malloc(sizeof(struct node));
    x-> data = a;
    x-> next = NULL;
    while(p-> next != NULL)
    {
        if(p-> next-> data > a)
        {
             x-> next = q-> next;
             q-> next = x;
             break;
        }

        p = p-> next;
        q = p;
    }

    if(p-> next == NULL)
    {
         x-> next = q-> next;
         q-> next = x;
    }

    return head;
}

void print(struct node *head)
{
    struct node *p;

    p = head;

    while(p-> next != NULL)
    {
        p = p-> next;
        printf("%d ", p-> data);
    }

}

int main(void)
{
    int n, a;
    struct node *x, *h;

    scanf("%d", &n);

    h = creat(n);

    scanf("%d", &a);
    x = sert(head, a);
    print(x);

    return 0;
}
