#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node *next;

}*a[1001], *p, *q;

int flag[10001], stack[10001];

void build(struct node *num[], int u, int v)
{
    // struct node *x;

    p = (struct node *)malloc(sizeof(struct node));
    p-> data = v;
    if(num[u] == NULL)
    {
        p-> next = NULL;
        num[u] = p;
    }

    else
    {
        p-> next = num[u]-> next;
        num[u]-> next = p;
    }

    q = (struct node *)malloc(sizeof(struct node));
    q-> data = u;
    if(num[v] == NULL)
    {
        q-> next = NULL;
        num[v] = q;
    }

    else
    {
        q-> next = num[v]-> next;
        num[v]-> next = q;
    }

}

int search(struct node *head, int i)
{
    while(head)
    {
       if(head -> data == i)
           return 1;
        else
            head = head -> next;
    }
    return 0;
}

int main(void)
{
    int n, i, k, m, t, u, v;

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d %d", &k, &m, &t);
        struct node *num[101] = {NULL};;
        memset(flag, 0, sizeof(flag));
        memset(stack, 0, sizeof(stack));

        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            build(num, u, v);
        }

        int l = 0, r = 0;
        flag[t] = 1;
        stack[r++] = t;

        while(l < r)
        {
            for(i = 0; i < k; i++)
            {
                if(search(num[stack[l]], i) && flag[i] == 0)
                {
                    stack[r++] = i;
                    flag[i] = 1;
                }
            }

            printf("%d%c", stack[l], l == k - 1?'\n':' ');
            l++;
        }
    }

    return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[110], flag[110];
struct node
{
    int data;
    struct node *next;
};
struct node *num[110];

void creat_list(int u, int v)
{
    struct node *p, *q;
    p = (struct node *)malloc(sizeof(struct node));
    p -> data = v;
    if(num[u] == NULL)
    {
        p -> next = NULL;
        num[u] = p;
    }
    else
    {
        p -> next = num[u] -> next;
        num[u] -> next = p;
    }
    q = (struct node *)malloc(sizeof(struct node));
    q -> data = u;
    if(num[v] == NULL)
    {
        q -> next = NULL;
        num[v] = q;
    }
    else
    {
        q -> next = num[v] -> next;
        num[v] -> next = q;
    }
}

int search(struct node *head, int i)
{
    while(head)
    {
       if(head -> data == i)
           return 1;
        else
            head = head -> next;
    }
    return 0;
}

int main()
{
    int t, n, m, k, u, v, i;
    scanf("%d", &t);
    while(t--)
    {
        memset(flag, 0, sizeof(flag));
        memset(stack, 0, sizeof(stack));
        scanf("%d%d%d", &n, &m, &k);
        for(i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            creat_list(u, v);
        }
        int l = 0, r = 0;
        flag[k] = 1;
        stack[r++] = k;
        while(l < r)
        {
           // printf("%d\n\n\n\n", n);
            for(i = 0; i < n; i++)
            {
                if(search(num[stack[l]], i) && flag[i] == 0)
                {
                    stack[r++] = i;
                    flag[i] = 1;
                }
            }
            printf("%d%c", stack[l], l == n - 1 ? '\n' : ' ');
            l++;
        }
    }
    return 0;
}
*/

