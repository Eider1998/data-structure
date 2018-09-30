#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[100001];

int main(void)
{
    int n, i, sum = 0, max = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n; i++)
    {
        if(sum + a[i] > 0)
        {
            sum += a[i];
            if(max < sum)
            {
                max = sum;
            }
        }

        else
        {
            sum = 0;
        }
    }

    printf("%d\n", max);
    return 0;
}
