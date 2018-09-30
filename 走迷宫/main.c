#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int e1 = 10050, e2 = 10050;
char a[100];
int num[100010], flag[100010];

int main(void)
{
    int m, i, b, j = 0, t;

    scanf("%d", &m);
    for(i = 1; i <= m; i++)
    {
        scanf("%s", a);//利用scanf的特点，遇到空格就停止，数字可以接下来继续输入
        if(strcmp(a, "LIN") == 0)
        {
            scanf("%d", &b);
            num[e1--] = b;
        }

        else if(strcmp(a, "RIN") == 0)
        {
            scanf("%d", &b);
            num[++e2] = b;
        }

        else if(strcmp(a, "ROUT") == 0)
        {
            if(e1 >= e2)
            {
                flag[j++] = i;
                e1 = 10050;
                e2 = 10050;
            }

            else
            {
                e2--;
            }
        }

        else
        {
            if(strcmp(a, "LOUT") == 0)
            {
                if(e1 >= e2)
                {
                    flag[j++] = i;
                    e1 = 10050;
                    e2 = 10050;
                }

                else
                {
                    e1++;
                }
            }
        }


    }

    if(e1 < e2)
    {
        for(i = e1 + 1; i <= e2; i++)
        {
            if(i == e2)
            {
                printf("%d\n", num[i]);
            }

            else
            {
                printf("%d ", num[i]);
            }
        }
    }

    /*if(e1 == e2)
    {
        printf("%d\n", num[e1]);
    }*/

    for(t = 0; t < j; t++)
    {
        printf("%d ERROR\n", flag[t]);
    }

    return 0;
}
