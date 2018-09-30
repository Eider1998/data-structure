#include<stdio.h>

int main(void)
{
    int n, i, a[1001], head, tail;

    n = 9;

    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    head = 0;
    tail = 9;


    while(head < tail)
    {
        printf("%d ", a[head]);
        head++;

        a[tail] = a[head];

        head++;
        tail++;

    }//注意此时最后一个数还没有输出来

   // printf("%d\n", a[head - 1]);

    return 0;
}
