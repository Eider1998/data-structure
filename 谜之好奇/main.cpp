#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(void)
{
    int n;
    int x;
    int a[100001];
    int s;
    int y;
    while(~scanf("%d", &n))
    {
        memset(a, 0, sizeof(a));
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            s = 10;
            while(1)
            {
                if(x % s == x)
                {
                    break;
                }
                int t = x % s;
                if(t >= s / 10)
                {
                    a[t]++;
                }
                s *= 10;
            }
        }
        int m;
        scanf("%d", &m);
        for(int  i = 0; i < m; i++)
        {
            scanf("%d", &y);
            printf("%d\n", a[y]);
        }
    }

    return 0;
}
