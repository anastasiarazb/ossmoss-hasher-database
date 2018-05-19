#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int diffStr(char *ps1, char *ps2)
{
        int i = 1;
        int count = 0;
        int minLen;
    
	minLen = (strlen(ps1) > strlen(ps2)) ? strlen(ps1) : strlen(ps2);
	
	for(i; i < minLen; i++)
		if(strncmp(ps1 + strlen(ps1) - i, ps2, i) == 0)
			count = i;
	return count;
}

void buildMatr(char **ps, int pn, int **pa)
{
	int i = 0;
        int j;
    
	for (i; i < pn; i++)
		for (j = 0; j < pn; j++)
			if (i != j)
				*(*(pa + i) + j) = diffStr(*(ps + i), *(ps + j));
			else
				*(*(pa + i) + j) = 0;
}

int getMax(int **pa, int pn, int *pc1, int *pc2)
{
        int max = **pa;
	int i = 0;
        int j;
         
	for (i; i < pn; i++)
		for (j = 0; j < pn; j++)
			if(*(*(pa + i) + j) > max)
			{
				*pc1 = i;
				*pc2 = j;
				max = *(*(pa + i) + j);
			}
	return max;
}

int matr(int **pa, int pn)
{
        int i;
        int j = 0;
	int ch1;
        int ch2;
        int max;
        int len = 0;
    
	max = getMax(pa, pn, &ch1, &ch2);
	
	while (max && (j < pn - 1))
	{
		j++;
		len += max;
		for (i = 0; i < pn; i++)
		{
			*(*(pa + ch1) + i) = 0;
			*(*(pa + i) + ch2) = 0;
		}
		max = getMax(pa, pn, &ch1, &ch2);
	}
	
	return len;
}
int main()
{
	char **s;
	int **a;
	int n;
        int i = 0;
        int j = 0;
        int len;
    
	scanf("%d\n", &n);
	a = (int**)malloc(sizeof(int*) * n);
	s = (char**)malloc(sizeof(char*) * n);
	
	for (i; i < n; i++)
	{
		*(a + i) = (int *)calloc(n, sizeof(int));
		*(s + i) = (char *)calloc(100, sizeof(char));
	}
	
	for (i = 0; i < n; i++)
	{
		gets(s[i]);
		j += strlen(s[i]);
	}
	
	buildMatr(s, n, a);
	len = matr(a, n);
	j -= len;
	printf("%d", j);
	
	for (i = 0; i < n; i++)
	{
		free(a[i]);
		free(s[i]);
	}
	
	free(a);
	free(s);
	return 0;
}
