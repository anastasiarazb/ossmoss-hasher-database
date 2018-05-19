#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int superSTR(char **s, int n);

int main(void)
{
        int n = 0;
	int i = 0;
	scanf("%d ", &n);
	char ** pArr = malloc(sizeof(char *) * n);
	if(pArr == NULL)
	{
		printf("MALLOC Error \n");
		return 1;
	}
	for(i = 0; i < n; i++)
	{
		pArr[i] = malloc(sizeof(char)*100);
		if(pArr[i] == NULL)
		{
			printf("MALLOC Error \n");
			return 1;
		}
		gets(pArr[i]);
	}
	printf("%d \n", superSTR(pArr, n));
	for(i = 0; i < n; i++)
	{
		free(pArr[i]);
	}
	free(pArr);
	return 0;
}

int superSTR(char **s, int n)
{
	int i = 0;
	int k = 0;	
	int j = 0;
	int z = 0;
	int y = 0;
	int length = 0;
	int count = 0;
	int result = 0;
	int * resultArr = malloc(sizeof(int) * n);
	int * numArr = malloc((n*n) * (sizeof(int)));
	for(i = 0; i < (n*n) ; i++)
	{
		numArr[i] = 0;
	}
	if(numArr == NULL ||resultArr == NULL)
	{
		printf("MALLOC Error \n");
	}	
	for(i = 0; i < n; i++)
	{
		length += strlen(s[i]);
		for(j = 0; j < n; j++)
		{
			k = strlen(s[i]) - strlen(s[j]);
			if(k < 0)
			{
				k = 0;
			}
			y = 0;
			for(z = k;z < strlen(s[i]);z++)
			{
				
				if((s[i][z] != s[j][y]))
				{
					k = k + 1;
					z = k - 1;;
					y = -1;
				}
				y++;
			}
			if(i != j)
			{
				numArr[i*n + j] = y;
			}
			//printf("%d ", numArr[i*n + j]);
		}
		//printf("\n");
	}
	for(j = 0; j < n; j++)
	{
		count = 0;
		for(i = 0; i < n;i++)
		{
			if(count < numArr[i*n + j])
			{
				count = numArr[i*n + j];
			}
		}
		resultArr[j] = count;
		result += resultArr[j];
	}
	count = 32767;
	for(i = 0; i < n; i++)
	{
		if(count > resultArr[i])
		{
			count = resultArr[i];
		}
	}
	result = length - result + count;
	free(numArr);
	free(resultArr);
	return result;
}