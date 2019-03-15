#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct node
{
    long long val;
}tree[500001];
long long data[500001];

void build(int root, int left, int right)
{
    if(left == right)
    {
        tree[root].val = data[left];
        return ;
    }
    int mid = (left + right) / 2;
    build(root * 2 + 1, left, mid);
    build(root * 2 + 2, mid + 1, right);
    tree[root].val = tree[root * 2 + 1].val + tree[root * 2 + 2].val;
}

void updata(int root, int left, int right, long long pos, long long val)
{
    if(left == right)
    {
        tree[root].val += val;
        return ;
    }
    int mid = (left + right) / 2;
    if(pos <= mid)
    {
        updata(root * 2 + 1, left, mid, pos, val);
    }
    else
    {
        updata(root * 2 + 2, mid + 1, right, pos, val);
    }
    tree[root].val = tree[root * 2 + 1].val + tree[root * 2 + 2].val;
}

long long query(int root, int left, int right, long long qleft, long long qright)
{
    long long res = 0;
    if(qleft <= left && qright >= right)
    {
        return tree[root].val;
    }
    int mid = (left + right) / 2;
    if(qleft <= mid)
    {
        res += query(root * 2 + 1, left, mid, qleft, qright);
    }
    if(qright > mid)
    {
        res += query(root * 2 + 2, mid + 1, right, qleft, qright);
    }
    return res;
}

int main(void)
{
    int n;
    while(~scanf("%d", &n))
    {
        memset(tree, 0, sizeof(tree));
        memset(data, 0, sizeof(data));
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &data[i]);
        }
        build(0, 0, n - 1);
        int q;
        scanf("%d", &q);
        long long x, y, z;
        while(q--)
        {
            scanf("%lld %lld %lld", &x, &y, &z);
            if(x == 1)
            {
                updata(0, 0, n - 1, y - 1, z);
            }
            else if(x == 2)
            {
                printf("%lld\n", query(0, 0, n - 1, y - 1, z - 1));
            }
        }
    }

    return 0;
}
