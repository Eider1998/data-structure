#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

struct Table
{
   int *num;
   int len;
};

void build_table(Table &a, int len);
int max_sum(Table a);
void delete_memory(Table &a);

int main(void)
{
    int n, m = 0;
    Table test;

    scanf("%d", &n);
    build_table(test, n);
    m = max_sum(test);
    printf("%d\n", m);
    delete_memory(test);

    return 0;
}

void build_table(Table &a, int len)
{
    a.len = len;
    a.num = new int [len + 4];
    for(int i = 1; i <= len; i++)
    {
        scanf("%d", &a.num[i]);
    }
}

int max_sum(Table a)
{
    int ans = 0, sum = 0;

    for(int i = 1; i <= a.len; i++)
    {
        sum += a.num[i];
        if(sum < 0)
        {
            sum = 0;
        }

        ans = max(ans, sum);

    }

    return ans;
}

void delete_memory(Table &a)
{
    delete []a.num;
}
