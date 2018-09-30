#include<stdio.h>
#include<string.h>
int main(void)
{
    char str1[100], str2[100], str3[100];
    int i, n, k = 0, t;

    printf("Enter a sentence: ");
    gets(str1);
    n = str1en(str1);
    for(i = 0; i < n; i++)
    {
        if(str1[i] != ' ')
        {
            str2[k++] = str1[i];
        }
        if(str1[i] == ' ')
        {
            t = i;
            break;
        }
    }
    for(i = t; i < n; i++)
    {
        str3[k++] = str1[i];
    }
    puts(str3);
    printf(", %c.", str2[0]);
    return 0;
}
