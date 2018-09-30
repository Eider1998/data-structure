#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

struct node
{
    int a, b;
    struct node *next;
}*p;

void creat(int n)
{
    node *x1, *x, *q, *tail;

    p = (node *)malloc(sizeof(node));
    q = (node *)malloc(sizeof(node));

    p-> a = 0;
    p-> b = 1;

    q-> a = 1;
    q-> b = 1;
    q-> next = NULL;
    p-> next = q;

    for(int i = 2; i <= n; i++)
    {
        tail = p;
        x = tail-> next;
        while(x != NULL)
        {
            if(tail-> b + x-> b <= n)
            {
                x1 = (node *)malloc(sizeof(node));
                x1-> b = tail-> b + x-> b;
                x1-> a = tail-> a + x-> a;
                x1-> next = x;
                tail-> next = x1;
            }

            tail = tail-> next;
            x = tail-> next;
        }
    }
}

void print(struct node *p)
{
    node *q;
    int i = 1;
    q = p;
    while(q != NULL)
    {
        if(i % 10 != 0)
        {
            i++;
            printf("%d/%d\t", q-> a, q-> b);
        }

        else
        {
            i++;
            printf("%d/%d\n", q-> a, q-> b);
        }

        q = q-> next;
    }

}

int main(void)
{
    int n;

    cin >> n;
    creat(n);
    print(p);

    return 0;
}
