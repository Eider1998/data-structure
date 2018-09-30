#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int a[1000][1000], b[1000], vis[1000], que[1000];

void bfs(int len, int m)
{
    memset(b, 0, sizeof(b));
    memset(vis, 0, sizeof(vis));
    memset(que, 0, sizeof(que));

    int i = 0, j, s = 0, e = 0;

    que[e++] = m;
    vis[m] = 1;
    b[i++] = m;

    while(s < e)
    {
        for(j = 0; j < len; j++)
        {
            if(a[que[s]][j] == 1 && !vis[j])
            {
                que[e++] = j;
                vis[j] = 1;
                b[i++] = j;
            }

        }
        s++;
    }

}

int main(void)
{
    int i, j, n, m, k, q, t;

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d %d %d", &k, &m, &t);
        memset(a, 0, sizeof(a));

        for(q = 0; q < m; q++)
        {
            scanf("%d %d", &i, &j);
            a[i][j] = 1;
            a[j][i] = 1;
        }

        bfs(k, t);

        for(i = 0; i < k; i++)
        {
            printf("%d%c", b[i], i == k - 1?'\n':' ');
        }
    }

    return 0;
}


