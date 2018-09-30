#include<stdio.h>
#include<string.h>

void sort(int a[], int l, int r)
{
    int i = l, j = r, key = a[l];
    if(l > r)
    {
        return ;
    }

    while(i < j)
    {
        while(i < j && a[j] >= key)
        {
            j--;
        }

        a[i] = a[j];

        while(i < j && a[i] <= key)
        {
            i++;
        }

        a[j] = a[i];
    }

    a[i] = key;
    sort(a, l, i - 1);
    sort(a, i + 1, r);
}

int main(void)
{
    int i, t[1000], q[1000];
    char s[5000];

    while(~scanf("%s", s))
    {
        int top = 0, rear = 0;
        memset(t, 0, sizeof(t));
        memset(q, 0, sizeof(q));

        int len = strlen(s);
        int sum1 = 8 * len;//ASCII一个字符占8个字节
        int sum2 = 0;

        for(i = 0; i < len; i++)
        {
            t[s[i] - '0']++;
        }

        for(i = 0; i < 256; i++)
        {
            if(t[i] != 0)
            {
                q[top++] = t[i];
            }
        }

        sort(q, 0, top - 1);
        while(top != rear)
        {
            int x1 = q[rear++];
            if(top != rear)
            {
                int x2 = q[rear++];
                sum2 += x1 + x2;
                q[top++] = x1 + x2;
                sort(q, rear, top - 1);
            }
        }

        printf("%d %d %.1lf\n", sum1, sum2, (sum1 * 1.0) / sum2);
    }

    return 0;
}
