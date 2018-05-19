#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 80

typedef int BOOL;
#define true 1
#define false 0




int nof_equal(const void *a, const void *b)
{
        char *str1 = *(char**)a;
	char *str2 = *(char**)b;

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int len_min = len1 < len2 ? len1 : len2;

	int i;

	int max = len1;

	for(i = 0; i < len1; i++)
	{
		if(begins_with(str2, (str1 + i)) == false)
			max--;
		else
			break;
	}

	return max;
}
int **get_matrix(char **strs, size_t nel, int (*extract)(const void *a, const void *b))
{
	int **matrix;
	size_t i, j;

	matrix = (int**)malloc(sizeof(*matrix) * nel);
	for(i = 0; i < nel; i++)
	{
		*(matrix + i) = (int*)malloc(sizeof(**matrix) * nel);
	}

	for(i = 0; i < nel; i++)
	{
		for(j = 0; j < nel; j++)
		{
			*(*(matrix + i) + j) = extract(strs + i, strs + j);
		}
	}

	return matrix;
}
int min_superstr_len(char** strs, size_t nel)
{
	int** matrix = get_matrix(strs, nel, nof_equal);

	int len = min_len(matrix, nel);

	while(nel-- > 0)
	{
		free(*(matrix + nel));
	}
	free(matrix);

	return len;
}
BOOL begins_with(char *str, char *beginning)
{
	int len = strlen(beginning);
	size_t i;
	BOOL begins = true;

	if(len > strlen(str))
		return false;
	for(i = 0; i < len; i++)
	{
		if(*(str + i) != *(beginning + i))
		{
			begins = false;
			break;
		}
	}

	return begins;
}
void swap(char *x, char *y, size_t typesize)
{
	char tmp;

	if (x != y)
	{
		while (typesize--)
		{
			tmp = *x;
			*x++ = *y;
			*y++ = tmp;
		}
	}
}
void get_next_config(int *a, size_t n)
{
	int i,j;
	for (i=n-1;i>0;--i)
	{
		if (*(a + i) > *(a + i - 1))
		{
			for (j=n-1; j>i; --j)
			{
				if (*(a + j) > *(a + i - 1))
					break;
			}
			swap(a + i - 1, a + j , sizeof(*a));
			break;
		}
	}
	for(j=n-1; j>i; --j, ++i)
		swap((char*)(a + i), (char*)(a + j), sizeof(*a));
}
long long factorial(int n)
{
	int i = n;
	long long fac = n;
	while(--i > 0)
	{
		fac *= i;
	}

	return fac;
}
int min_len(int **matrix, size_t nel)
{
	size_t i;
	long long tryal_ind = 0;
	long long fac = factorial((int)nel);

	int min = trace(matrix, nel);

	int *count_arr = (int*)malloc(sizeof(*count_arr) * nel);
	for(i = 0; i < nel; i++)
		*(count_arr + i) = i;

	while(tryal_ind++ < fac)
	{
		int len = get_len(matrix, nel, count_arr);

		if(min > len)
			min = len;

		get_next_config(count_arr, nel);
	}

	free(count_arr);
	return min;
}



int trace(int **matrix, size_t nel)
{
	size_t i;
	int tr = 0;

	for(i=0; i<nel; i++)
	{
		tr += *(*(matrix + i) + i);
	}

	return tr;
}

int get_len(int **matrix, size_t nel, int *count_arr)
{
	int i, sum=0, index_curr, index_next;

	for(i=0; i<nel; i++)
	{
		index_curr = *(count_arr + i);
		sum += *(*(matrix + index_curr) + index_curr);

		if(i != nel-1)
		{
			index_next = *(count_arr + i + 1);
			sum -= *(*(matrix + index_curr) + index_next);
		}
	}

	return sum;
}
int main(int argc, char** argv)
{
	int i,len,num = 0;
	char **strs;
	scanf("%i", &num);
	strs = (char**)malloc(sizeof(*strs) * num);
	for(i=0;i<num;i++)
	{
		*(strs + i) = (char*)malloc(MAX * sizeof(char));
		scanf("%s", *(strs + i));
	}

	len = min_superstr_len(strs, num);
	printf("%d\n", len);
	for(i=0;i<num;i++)
	{
		free(*(strs + i));
	}
	free(strs);

	return 0;
}