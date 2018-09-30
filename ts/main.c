#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str1[10001], str2[10001];

int main(void)
{
    int i, j, flag, n, jin;

    while(gets(str1) != NULL)
    {
        n = strlen(str1);
        jin = 0;
        flag = 0;
        memset(str2, 0, sizeof(str2));

        for(i = 0; i < n; i++)
        {
            if(str1[i] == '#')
            {
                if(i == 0)
                {
                    for(j = 0; j < n - 1; j++)
                    {
                        str1[j] = str1[j + 1];
                    }

                    i = -1;
                    n--;
                    continue;
                }

                else
                {
                    jin -= 1;
                }
            }

            else if(str1[i] == '@')
            {
                memset(str2, 0, sizeof(str2));
                jin = 0;
            }

            else
            {
                str2[jin++] = str1[i];
            }
        }

        if(!flag)
        {
            printf("%s\n", str2);
        }
    }

    return 0;
}
