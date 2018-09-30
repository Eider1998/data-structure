#include<stdio.h>
#include<string.h>

int main(void)
{
    int n, m, i, k, a[11000];
    char s[10];

    scanf("%d", &m);
    for(i = 1; i <= m; i++)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", s);
        if(strcmp(s, "JOIN") == 0)
        {
            scanf("%d", &a[i++]);
            m++;
        }

        else if(strcmp(s, "LEAVE") == 0)
        {
            scanf("%d", &k);
            for(i = k; i < m; i++)
            {
                a[i] = a[i + 1];
            }
            m--;
        }

        else if(strcmp(s, "ASK") == 0)
        {
            scanf("%d", &k);
            printf("%d\n", a[k]);
        }

        else if(strcmp(s, "FINISH") == 0)
        {
            scanf("%d", &k);
            for(i = 1; i <= m - k; i++)
            {
                a[i] = a[i + k];
            }
            m = m - k;
        }

        else
        {
            printf("%d\n", m);
        }
    }

    return 0;
}
