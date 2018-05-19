#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int helper(char* t, char* s) {
        int i, j, k, res = 0;
	for (i = 1; t[i] != '\0'; i++) {
		k = 0;
		for (j = i; t[j] != '\0' && s[k] != '\0'; j++) {
			if (t[j] != s[k]) {
        			k = 0;
				break;
			}
			k++;
		}
		if (k > res) res = k;
	}
	return res;
}

void append(char* f, char* s, int ind) {
	f[ind] = '\0';
	strncat(f, s, 10000);
	s[0] = '\0';
}

int super(char** arr, int len) {
	int k = 1, max, f, s, i, j, c, ind;
	while(k < len) {
		max = -1;
		for (i = 0; i < len; i++)
			for (j = 0; j < len; j++)
				if (i != j && arr[i][0] != '\0' && arr[j][0] != '\0') {
					c = helper(arr[i], arr[j]);
					if (c > max) {
						max = c;
						f = i;
						s = j;
					}
				}
		ind = strlen(arr[f]) - max;
		append(arr[f], arr[s], ind);
		k++;
	}
	printf("%lu\n", strlen(arr[f]));
	return 0;
}

int main(int argc, char **argv)
{
	int n, i;
	scanf("%d", &n);
	char **arr = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < n; i++) {
		arr[i] = (char*)malloc(sizeof(char) * 10000);
		scanf("%s", arr[i]);
	}
	super(arr, n);
	for (i = 0; i < n; i++)
		free(arr[i]);
	free(arr);
	return 0;
}