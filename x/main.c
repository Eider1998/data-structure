#include<stdio.h>
#include<string.h>

int main(void)
{
    char a[80], *p;

    p = a;

    scanf("%s", p);

    while(*p != '\0')
    {
       // printf("%d\n", p - a);
        p++;
    }

    printf("%d\n", p - a);

    return 0;
}
