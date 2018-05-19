#include <stdio.h>
#include <string.h>

char A[10][100];
char Sup[1000];

int overlap (int str1, int str2)
{
        int i, j;
	j = 0;
	i = 0;
	while (i < strlen (A[str1]))
	{
		if (A[str1][i] == A[str2][j])
			++j;
		else if (j >= 1 && A[str1][i] != A[str2][j])
		{
			--i;
			j = 0;
		}
		else
			j = 0;
		++i;
	}
	
	return j;
}

char cut (int a, int b, int maxoverlap)
{
	A[a][strlen (A[a]) - maxoverlap] = 0;
	strcat (A[a], A[b]);
	strcpy (A[b], A[a]);
	A[a][0] = '\0';
}

int main(int argc, char **argv)
{
	int n, i, j, maxi, maxj, k;
	int maxoverlap;
	int curoverlap;
	n = 0;
	scanf ("%d", &n);
	for (i = 0; i < n; ++i)
		scanf ("%s", &A[i][0]);
	if (n == 1)
	{
		printf ("%d", strlen (A[0]));
		return 0;
	}
	for (k = 0; k < n; ++k)
	{
		maxoverlap = -1;
		for (i = 0; i < n; ++i)
			for (j = 0; j < n; ++j)
			{
				if (i == j)
					continue;
				if (strlen (A[i]) > 0 && strlen (A[j]) > 0)
				{
					curoverlap = overlap (i, j);
					if (curoverlap > maxoverlap)
					{
						maxoverlap = curoverlap;
						maxi = i;
						maxj = j;
					}
				}
			}
		cut (maxi, maxj, maxoverlap);
	}
		for (i = 0; i < n; ++i)
			if (strlen (A[i]) > 0)
				printf ("%d", strlen (A[i]));
	return 0;
}