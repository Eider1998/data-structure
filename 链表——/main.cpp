#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

struct node
{
    int data;
    struct node *next, *prior;
}*head;

void create (int n)
{
   node *p, *q;
   q = head;

   for(int i = 0; i < n; i++)
   {
       p = new node;
       cin >> p-> data;

       p-> next = NULL;
       q-> next = p;
       p-> prior = q;
       p = q;
   }
}

void search_num(int x)
{
   node *p;
   p = head-> next;

   while(p != NULL)
   {
       if(p-> data == x)
       {
           if(p-> prior != head && p-> next != NULL)
           {
               printf("%d %d\n", p-> prior-> data, p-> next-> data);
               break;
           }

           else if(p-> prior != head && p-> next == NULL)
           {
               printf("%d\n", p-> prior-> data);
               break;
           }

           else if(p-> prior == head && p-> next != NULL)
           {
               printf("%d\n", p-> next-> data);
               break;
           }
       }

       else
       {
           p = p-> next;
       }
   }
}

int main(void)
{
    int n, m, x;

    cin >> n >> m;
    head = new node;
    head-> next = head-> prior = NULL;

    create(n);
    while(m--)
    {
        cin >> x;
        search_num(x);
    }

    return 0;
}
