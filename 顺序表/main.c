#include<stdio.h>
#include<stdlib.h>
#define maxsize 100000
typedef struct
{
    int *elem;
    int lenth, listsize;
}sq;

int intilist(sq *l)
{
    l-> elem = (int *)malloc(maxsize * sizeof(int));
    if(!l-> elem)
    {
        return -1;
    }

    l-> lenth = 0;
    l-> listsize = maxsize;
    return 0;
}

void insertlist(sq *l, int n)
{
    int i;
    l-> lenth = n;

    for(i = 0; i < l-> lenth; i++)
    {
        scanf("%d", &l-> elem[i]);
    }
}

int findlist(sq *l, int x, int t, int r)
{
    int mid;

    while(t > r)
    {
        return -1;
    }

    while(t <= r)
    {
        mid = (t + r) / 2;
        if(l-> elem[mid] == x)
        {
            return mid + 1;
        }

        else if(l-> elem[mid] > x)
        {
           return findlist(l, x, t, mid - 1);
        }

        else
        {
            return findlist(l, x, mid + 1, r);
        }
    }


}

int main(void)
{
    int t, n, x, q;
    sq l;
    scanf("%d", &n);
    intilist(&l);
    insertlist(&l, n);

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &x);

        q = findlist(&l, x, 0, n - 1);

        if(q != -1)
        {
           printf("%d\n", q);
        }
        else
        {
            printf("No Found!\n");
        }
    }

    return 0;
}
