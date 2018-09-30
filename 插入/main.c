#include<stdio.h>
#include<string.h>

void insertc(char str[], char c, int n)
{
    int i, len;

    len = strlen(str);

    str[n - 1] = c;

    for(i = n - 1; i <= len; i++)
    {
        str[i + 1] = str[i];
    }
}

int main(void)
{
    int n, i, len;
    char str[10001], c;

    gets(str);
    len = strlen(str);
    scanf("%c", &c);


    scanf("%d", &n);

    insertc(str, c, n);

    for(i = 0; i <= len; i++)
    {
        printf("%c", str[i]);
    }

    return 0;
}
