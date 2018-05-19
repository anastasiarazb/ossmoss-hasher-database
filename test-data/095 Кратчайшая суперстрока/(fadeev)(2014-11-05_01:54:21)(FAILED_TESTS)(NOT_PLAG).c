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
	int countMax = 0;
	int countSum = 0;
	int min = 100;
	int maxI = 0;
	int maxJ = 0;
	int length = 0;
	int * numArr = calloc((n*n),(sizeof(int)));
	if(numArr == NULL)
	{
		printf("MALLOC Error \n");
		return 0;
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
			printf("%d ", numArr[i*n + j]);
		}
		printf("\n");
	}
	for(k = 0; k < n; k++)
	{
		countMax = 0;
		for(i = 0; i < n; i++)
		{
			for(j = 0; j < n; j++)
			{
				if(numArr[i*n + j] > countMax)
				{
					countMax = numArr[i*n + j];
					maxI = i;
					maxJ = j;
				}
			}
		}
		for(z = 0; z < n; z++)
		{
			numArr[maxI*n + z] = 0;
			numArr[z*n + maxJ] = 0;
		}
		if(min > countMax)
		{
			min = countMax;
		}
		countSum += countMax;
	}
	countSum -= min;
	free(numArr);
	return length - countSum;
}