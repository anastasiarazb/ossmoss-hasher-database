#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STRING 100

int overlap(char *t, char *s)
{
        int i, j, k, max;
	k = max = 0;
	for (i = 1; t[i]; ++i) {
		for(j = i; t[j] && s[k]; ++j) {
			if (t[j] != s[k]){
				k = 0;
				break;
			}
			++k;
		}
		if (k > max) max = k;
		k = 0;
	}
	return max;
}

void addstring(int overlap, char *str1, char* str2)
{
	str1[strlen(str1) - overlap] = 0;
	strcat(str1, str2);
	str2[0] = 0;
}

int main()
{
	int i, n, j, k, m, str1, str2, result;
	scanf("%d", &n);
	char **arr =(char**)calloc(n, sizeof(char*));
	for(i = 0; i < n; ++i){
		arr[i]=(char*)calloc(STRING, sizeof(char));
		scanf("%s", arr[i]);
	}
	for (k = 1; k < n; ++k){
		for (i = 0, m = -1; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				if (i != j && arr[i][0] && arr[j][0]) {
					int over = overlap(arr[i], arr[j]);
					if (over > m){
						m = over;
						str1 = i;
						str2 = j;
					}
				}
			}
		}
		addstring(m, arr[str1], arr[str2]);
		result = str1;
	}
	printf("%d\n", (int)strlen(arr[result]));
	for(i = 0; i < n; ++i) free(arr[i]);
	free(arr);
	return 0;
}