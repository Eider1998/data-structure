#include<stdio.h>
#include<string.h>

void insertc(char str[],char c,int n)
{
	int i,count=0;

	count = strlen(str);
	if(count>n)
	{
		for(i = n + 1; i <= count; i++)
        {
            str[i] = str[i - 1];
        }
		 str[n]=c;
	}

	else
    {
        str[n] = c;
    }
}

int main()
{
	char str[40],c;
	int n, len, i;
	scanf("%s",str);
	getchar();
	scanf("%c",&c);
	scanf("%d",&n);
	insertc(str,c,n);
    len = strlen(str);

	for(i = 0; i < len; i++)
    {
        printf("%c", str[i]);
    }

	return 0;
}
