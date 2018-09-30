/*
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
         puts(a);

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
*/

