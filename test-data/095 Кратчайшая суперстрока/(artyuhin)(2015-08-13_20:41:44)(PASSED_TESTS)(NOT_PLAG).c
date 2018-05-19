#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fun(char *t, char *mas)
{
        int i, k, j, res;
	for (i = 1, res = k = 0; t[i]; ++i, k = 0)
	{
		for (j = i; t[j] && mas[k]; ++j, ++k)
			if (t[j] != mas[k])
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
	char **str = (char**)calloc(n, sizeof(char*));
	for (i = 0; i < n; ++i)
	{
		str[i] = (char*)calloc(100, sizeof(char));
		scanf("%s", str[i]);
	}
	for (k = 1; k < n; ++k)
	{
		for (i = 0, max = -1; i < n; ++i)
			for (j = 0; j < n; ++j)
				if (i != j && str[i][0] && str[j][0])
				{
					int cur = fun(str[i], str[j]);
					if (cur > max)
						max = cur, first = i, second = j;
				}
		append(str[first], str[second], max);
		res = first;
	}
	printf("%d\n", strlen(str[res]));
	for (i = 0; i < n; ++i)
		free(str[i]);
	free(str);
	return 0;
}