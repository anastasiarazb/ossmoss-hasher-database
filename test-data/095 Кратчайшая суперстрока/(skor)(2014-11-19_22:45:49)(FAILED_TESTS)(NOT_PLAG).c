
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int match(char *b, char *a)
{
        int la = strlen(a), lb = strlen(b);
	int *pi, i, t;

	pi = (int*)malloc(la * sizeof(int));

	for (pi[0] = t = 0, i = 1; i < la; i++) {
		while (t > 0 && a[t] != a[i]) t = pi[t-1];
		if (a[t] == a[i]) t++;
		pi[i] = t;
	}

	for (t = 0, i = 0; i < lb; i++) {
		while (t > 0 && a[t] != b[i]) t = pi[t-1];
		if (a[t] == b[i]) t++;
		if (t == la) {
			t = la == lb ? -1 : -2;
			break;
		}
	}

	free(pi);
	return t;
}

int solve(int m, char **strings)
{
	int **matrix, i, j, len;
	matrix = (int**)malloc(m * sizeof(int*));

	for (i = len = 0; i < m; i++) len += strlen(strings[i]);

	for (i = 0; i < m; i++) {
		matrix[i] = (int*)malloc(m * sizeof(int));
		for (j = 0; j < m; j++) {
			matrix[i][j] = i == j ? 0 : match(strings[i], strings[j]);
		}
	}

	/*for (i = 0; i < m; i++) {
		printf("%10s", strings[i]);
		for (j = 0; j < m; j++) {
			printf("%2d ", matrix[i][j]);
		}
		printf("\n");
	}*/

	for (i = 0; i < m; i++) {
		for (j = 0; j < m; j++) {
			if (matrix[i][j] < 0) {
				len = -1;
				goto END;
			}
		}
	}

	int permutation()
	{
		int max_sum = 0, level = 0;

		void visit(int mark, int k, int sum)
		{
			level++;
			mark |= 1 << k;

			if (level == m) {
				if (max_sum < sum) max_sum = sum;
			} else {
				int i;
				for (i = 0; i < m; i++) {
					if ((mark & (1 << i)) == 0) {
						visit(mark, i, sum+matrix[k][i]);
					}
				}
			}

			level--;
		}

		for (i = 0; i < m; i++) visit(0, i, 0);
		return max_sum;
	}

	len -= permutation();

	END:
	for (i = 0; i < m; i++) free(matrix[i]);
	free(matrix);
	return len;
}

int main(int argc, char *argv[])
{
	int string_num, i;
	char **ss;

	scanf("%d\n", &string_num);
	ss = (char**)malloc(string_num * sizeof(char*));
	for (i = 0; i < string_num; i++) {
		ss[i] = (char*)malloc(100);
		gets(ss[i]);
	}

	printf("%d\n", solve(string_num, ss));

	for (i = 0; i < string_num; i++) free(ss[i]);
	free(ss);
	return 0;
}
