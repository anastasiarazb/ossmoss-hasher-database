#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int superSTR(char **s, int n);
void calc(int n, int i, int count, int *a, int *b);

int maxDelete = 0;

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

void calc(int n, int i, int count, int *a, int *b) 
{	
	int j = 0;
	int * saveArr = malloc(n*n * sizeof(int));
	for(j = 0; j < n*n; j++)
	{
		saveArr[j] = a[j];
	}
	for(j = 0; j < n; j++)
	{
		saveArr[j*n + i] = 1;
	}
	j = 0;
	while(j != n)
	{
		while(saveArr[i*n + j] == 1 && j != n)
		{
			j++;
		}
		if(j == n)
		{
			break;
		}
		calc(n, j, (count+b[i*n + j]), saveArr, b);
		j++;
	}
	if(count > maxDelete)
	{
		maxDelete = count;
	}
	free(saveArr);
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
	int nFact = 1;
	int * countArr = calloc(n*n, sizeof(int));
	int * numArr = malloc((n*n) * (sizeof(int)));
	for(i = 0; i < (n*n) ; i++)
	{
		numArr[i] = 0;
	}
	if(numArr == NULL ||countArr == NULL)
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
			printf("%d ", numArr[i*n + j]);
		}
		printf("\n");
	}
	for(i = 0; i < n; i++)
	{
		calc(n, i, 0, countArr, numArr);
	}
	free(numArr);
	free(countArr);
	return length - maxDelete;
}