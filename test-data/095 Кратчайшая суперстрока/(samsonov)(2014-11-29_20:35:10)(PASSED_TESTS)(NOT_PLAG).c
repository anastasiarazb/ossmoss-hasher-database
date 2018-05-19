#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

void swap(int *a, int i, int j)
{
        int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

int overlap(char *T, char *S)
{
	int i, k, j, res;
	for (i = 1, res = 0; T[i]; ++i)
	{
		for (j = i, k = 0; T[j] && S[k]; ++j, ++k)
			if (T[j] != S[k])
			{
				k = 0;
				break;
			}
		res = k > res ? k : res;
	}
	return res;
}

void superstring(int *p, char **strings, int **table, int m, int n, int *min)
{
	int i, j, length;
	if (m == 1)
	{
		for (i = 1, length = 0; i < n; ++i)
			length += strlen(strings[p[i - 1]]) - table[p[i - 1]][p[i]];
		if ((length += strlen(strings[p[n - 1]])) < *min)
			*min = length;
	}
	else
		for (i = 0; i < m; ++i)
		{
			superstring(p, strings, table, m - 1, n, min);
			j = m & 1 ? 1 : i;
			swap(p, j, m - 1);
		}
}

void overlap_table(char **strings, int **table, int n)
{
	int i, j;
	for (i = 0; i < n; ++i)
		for (j = 0; j < n; ++j)
			if (i != j)
				table[i][j] = overlap(strings[i], strings[j]);
}

int main()
{
	int n, *p, **table, i, res = 1000;
	char **strings;
	scanf("%d", &n);
	strings = calloc(n, sizeof(char*));
	p = calloc(n, sizeof(int));
	table = calloc(n, sizeof(int*));
	for (i = 0; i < n; p[i] = i++)
	{
		strings[i] = calloc(SIZE, sizeof(char));
		table[i] = calloc(n, sizeof(int));
		scanf("%s", strings[i]);
	}
	overlap_table(strings, table, n);
	superstring(p, strings, table, n, n, &res);
	printf("%d\n", res);
	for (i = 0; i < n; ++i)
		free(strings[i]), free(table[i]);
	free(strings), free(table), free(p);
	return 0;
}