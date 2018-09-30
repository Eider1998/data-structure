#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int n, m, a, hash[1550], ans[1550];

    while(~scanf("%d %d", &n, &m))
    {
        int i;

        for(i = 0; i <= m; i++)
        {
            hash[i] = -1;
        }
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a);
            if(hash[a % m] == -1 || hash[a % m] == a)
            {
                hash[a % m] = a;
                ans[i] = a % m;
            }

            else
            {
                int j = 1;
                while(hash[(a % m + j) % m] != -1 || hash[(a % m + j) % m] != a)
                {
                    j++;
                }

                if(hash[(a % m + j) % m] == -1)
                {
                    hash[(a % m + j) % m] = a;
                    ans[i] = (a % m + j) % m;
                }

                else
                {
                    ans[i] = (a % m + j) % m;
                }
            }
        }

        for(i = 0; i < n; i++)
        {
            printf("%d%c", ans[i], i == n - 1?'\n':' ');
        }

    }

    return 0;
}
