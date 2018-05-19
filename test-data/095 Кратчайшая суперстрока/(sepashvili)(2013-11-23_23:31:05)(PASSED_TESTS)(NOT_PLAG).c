#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <ctype.h>

void prefix_function(const char *s, const char *t, int *pf_values)
{
        int i = 0;
	int j = 0;
	int s_l = strlen(s);
	int t_l = strlen(t);
	pf_values[0] = 0;
	for (i = 1; i < s_l + t_l + 1; ++i)
	{
		j = pf_values[i - 1];
#define str(k) (k <= s_l ? s[k] : t[k - s_l - 1])
		for (; j > 0 && str(i) != str(j); j = pf_values[j - 1]);
		if (str(i) == str(j))
#undef str
		{
			++j;
		}
		pf_values[i] = j;
	}
}

int max_intersections[10][10] = {{0}};
int visited[10] = {0};
int permutation[10] = {0};
char *strings[10];
int lengths[10];

int solve(int k, int current_sum, int from, int n)
{
	int i = 0;
	int tmp = 0;
	int min = 10000000;
	if (k == n)
	{
		return current_sum;
	}
	for (i = 0; i < n; ++i)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			permutation[k] = i;
			tmp = solve(k + 1, current_sum + lengths[i] - max_intersections[i][from], i, n);
			if (tmp < min)
			{
				min = tmp;
			}
			visited[i] = 0;
		}
	}
	return min;
}

int _solve(int n)
{
	int i = 0;
	int tmp = 0;
	int min = 10000000;
	for (i = 0; i < n; ++i)
	{
		visited[i] = 1;
		permutation[0] = i;
		tmp = solve(1, lengths[i], i, n);
		if (tmp < min)
		{
			min = tmp;
		}
		visited[i] = 0;
	}
	return min;
}

int main()
{
	int n = 0;
	int i = 0;
	int j = 0;
	int *pf = NULL;
	char c;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		strings[i] = (char *)malloc(1);
		lengths[i] = 0;
		strings[i][0] = 0;
		for (c = ' '; !feof(stdin) && isspace(c); scanf("%c", &c));
		for (; !feof(stdin) && !isspace(c); scanf("%c", &c))
		{
			strings[i][lengths[i]++] = c;
			strings[i] = (char *)realloc(strings[i], lengths[i] + 1);
			strings[i][lengths[i]] = 0;
		}
	}

	for (i = 0; i < n - 1; ++i)
	{
		max_intersections[i][i] = 0;
		for (j = i + 1; j < n; ++j)
		{
			pf = (int *)malloc(sizeof(int) * (lengths[i] + lengths[j] + 1));
			prefix_function(strings[i], strings[j], pf);
			max_intersections[i][j] = pf[lengths[i] + lengths[j]];
			prefix_function(strings[j], strings[i], pf);
			max_intersections[j][i] = pf[lengths[i] + lengths[j]];
			free(pf);
		}
	}
	for (i = 0; i < n; free(strings[i++]));
	printf("%d\n", _solve(n));
	return 0;
}