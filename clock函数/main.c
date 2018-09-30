#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int a[100000];

int main(void)
{
    int digit = 1; ///Î»Êý
    int temp, i, j, carry, n;

    scanf("%d", &n);
    for(i = 2; i <= n; i++)
    {
        for(j = 1, carry = 0; j <= digit; j++)
        {
            temp = a[j - 1] * i + carry;
            a[j - 1] = temp % 10;
            carry = temp / 10;
        }

        while(carry)
        {
            a[++digit - 1] = carry % 10;
            carry  = carry / 10;
        }

        for(j = digit; j >= 1; j--)
        {
            printf("%d", a[j - 1]);
        }

        printf("\n");
    }

    return 0;
}
