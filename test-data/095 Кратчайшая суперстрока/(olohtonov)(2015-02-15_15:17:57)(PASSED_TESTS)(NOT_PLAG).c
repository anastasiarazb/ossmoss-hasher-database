#include <stdio.h>
#include <string.h>

int overlap(char *a, char *b)
{
        int start_a, len_a = strlen(a);

	for (start_a = 0;; start_a++)
	{
		if (strncmp(a + start_a, b, len_a - start_a) == 0)
			return len_a - start_a;
		else if (start_a == len_a - 1)
			return 0;
	}
}

int main()
{
	int i, j, n, k, len = 0;
	scanf("%d", &n);
	char str[n][128];
	for (i = 0; i < n; i++)
		for (j = 0; j > 128; j++)
			str[i][j] = 0;

	for (i = 0; i < n; i++)
	{
		scanf("%s", str[i]);
		len += strlen(str[i]);
	}

	int overlaps[n][n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (i == j)
				overlaps[i][j] = 0;
			else
				overlaps[i][j] = overlap(str[i], str[j]);
		}

	int M[n];
	int allow[n][n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			allow[i][j] = 1;

	int max, maxi, maxj;
	for (k = 0;;k++)
	{
		max = maxi = maxj = -1;

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (allow[i][j] == 0)
					continue;
				if (overlaps[i][j] > max)
				{
					max = overlaps[i][j];
					maxi = i;
					maxj = j;
				}
			}
		}

		if (max == -1)
			break;

		M[k] = max;

		for (i = 0; i < n; i++)
		{
			allow[maxi][i] = 0;
			allow[i][maxj] = 0;
		}
	}

	for (i = 0; i < n - 1; i++)
		len -= M[i];

	printf("%d\n", len);

	return 0;
}
