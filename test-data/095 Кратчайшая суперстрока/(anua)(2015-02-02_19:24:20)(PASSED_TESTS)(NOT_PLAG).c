#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Overlap(char *T, char *S)
{
        int i, k, j, res;
	for (i = 1, res = k = 0; T[i]; ++i, k = 0)
	{
		for (j = i; T[j] && S[k]; ++j, ++k)
			if (T[j] != S[k])
			{
				k = 0;
				break;
			}
		if (k > res)
			res = k;
	}
	return res;
}

void append(char *first, char *second, int overlap)
{
	first[strlen(first) - overlap] = '\0';
	strcat(first, second);
	second[0] = '\0';
}

int main()
{
	int n, i, j, k, max, first, second, res;
	scanf("%d", &n);
	char **arr = calloc(n, sizeof(char*));
	for (i = 0; i < n; ++i)
	{
		arr[i] = calloc(100, sizeof(char));
		scanf("%s", arr[i]);
	}
	for (k = 1; k < n; ++k)
	{
		for (i = 0, max = -1; i < n; ++i)
			for (j = 0; j < n; ++j)
				if (i != j && arr[i][0] && arr[j][0])
				{
					int cur = Overlap(arr[i], arr[j]);
					if (cur > max)
						max = cur, first = i, second = j;
				}
		append(arr[first], arr[second], max);
		res = first;
	}
	printf("%d\n", (int) strlen(arr[res]));
	for (i = 0; i < n; ++i)
		free(arr[i]);
	free(arr);
	return 0;
}