/*
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i, t, m, n, T, j;
    char s[1001], a[101];

    scanf("%d", &T);
    for(t = 0; t < T; t++)
    {
        j = 0;
        scanf("%d %d", &m, &n);
        for(i = 0; i < n; i++)
        {
            scanf("%s", s);

            if(s[0] == 'P')
            {
                if(j <= m)
                {
                   a[j++] = s[2];
                }

                else
                {
                    printf("F\n");
                }
            }

            if(s[0] == 'O')
            {
                if(j == 0)
                {
                    printf("E\n");
                }

                else
                {
                   j -= 1;
                }
            }

            if(s[0] == 'A')
            {
                if(j == 0)
                {
                    printf("E\n");
                }

                else
                {
                    printf("%c\n", a[j - 1]);
                }
            }
        }

        if(t < T - 1)
        {
            printf("\n");
        }

    }

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t, n, m, b, top;
    char a[15];
    int stack[108];
    scanf("%d", &t);
    while(t--)
    {
       top = -1;
       scanf("%d %d", &m, &n);
       while(n--)
       {
         scanf("%s", a);
         if(a[0]=='P')
         {
            scanf("%d", &b);
            int p = top;
            p++;
            if(p>=m)
            printf("F\n");
            else
            stack[++top] = b;
         }
         if(a[0]=='O')
         {
            if(top<0)
            printf("E\n");
            else
            {
            printf("%d\n", stack[top]);
            top--;
            }
         }
         if(a[0]=='A')
         {
           if(top<0)
           printf("E\n");
           else
            printf("%d\n", stack[top]);
         }
       }
       if(t>0)
       printf("\n");
    }
    return 0;
}
