#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int x, y;

} a[1010], s1[1010], s2[1010];

int main(void)
{
    int i, i1, i2, j1, j2, n, m;
    double s = 0.0;

    scanf("%d", &m);

    while(m--)
    {
        int t;
        s = 0;
        i1 = i2 = j1 = j2 = 0;

        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
        scanf("%d", &n);

        for(i = 0; i < n; i++)
        {
            scanf("%d %d", &a[i].x, &a[i].y);
            for(t = i1; t < j1; t++)
            {
                if(a[i].x >= s1[t].y)
                {
                    i1++;
                }
            }

            for(t = i2; t < j2; t++)
            {
                if(a[i].x >= s2[t].y)
                {
                    i2++;
                }
            }

            if(j1 - i1 <= j2 - i2)
            {
                if(j1 - i1 != 0)
                {
                    s1[j1].y = s1[j1 - 1].y + a[i].y;
                }

                else
                {
                    s1[j1].y = a[i].x + a[i].y;
                }

                s += s1[j1].y - a[i].x;
                j1++;
            }

            else
            {
                if(j2 - i2 != 0)
                {
                    s2[j2].y = s2[j2 - 1].y + a[i].y;
                }

                else
                {
                    s2[j2].y = a[i].x + a[i].y;
                }

                s += s2[j2].y - a[i].x;
                j2++;
            }
        }

        printf("%.2lf\n", s / n);
    }

    return 0;
}
