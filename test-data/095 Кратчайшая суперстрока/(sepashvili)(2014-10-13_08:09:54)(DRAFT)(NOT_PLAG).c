#include <stdio.h>
#include <stdlib.h>

int main ()
{
        int n,i;
	scanf("%d", &n );
	char arr[n][100];
	for(i = 0 ; i <= n ; i++)
	{
		gets(arr[i]);
	}
	for(i = 0; i < 6; i++)
	{
		if(arr[1][i]==arr[2][i])
		{
			printf("%d\n", 5 );
		}
	}
	return 0;
}