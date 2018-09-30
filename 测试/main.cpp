#include<iostream>
#include<cstdlib>
using namespace std;

struct Table
{
    int *num;
    int m, len;
};

void build_table(Table &a, int len, int m);
void rebuild_table(Table &a);
void swap_num(Table &a, int l, int r);
void pri_num(Table &a);
void delete_memory(Table &a);

int main(void)
{
    int len, m, T;
    Table test;

    cin >> T;

    while(T--)
    {
        cin >> len >> m;
        build_table(test, len, m);
        rebuild_table(test);
        pri_num(test);
        delete_memory(test);
    }

    return 0;
}

void build_table(Table &a, int len, int m)
{
    a.len = len, a.m =  m;
    a.num = new int [len + 4];

    for(int i = 1; i <= a.len; i++)
    {
        cin >> a.num[i];
    }
}

void rebuild_table(Table &a)
{
    swap_num(a, 1, a.m);
    swap_num(a, a.m + 1, a.len);
    swap_num(a, 1, a.len);
}

void swap_num(Table &a, int l, int r)
{
    int mid = (l + r) / 2, t;

    for(int i = l; i <= mid; i++)
    {
        t = a.num[i], a.num[i] = a.num[l + r - i], a.num[r + l - i] = t;
    }
}

void pri_num(Table &a)
{
    for(int i = 1; i <= a.len; i++)
    {
        cout << a.num[i];
        i == a.len ? cout << '\n' : cout << ' ';
    }
}

void delete_memory(Table &a)
{
    delete []a.num;
}
