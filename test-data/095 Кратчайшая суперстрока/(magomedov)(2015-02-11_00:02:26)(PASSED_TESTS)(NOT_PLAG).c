#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int overlapping(char *oneString, char *secondString) {
        int i, k, j, result;
	for (i = 1, result = k = 0; oneString[i]; ++i, k = 0) {
		j = i;
		do {
			if (oneString[j] != secondString[k]) {
				k = 0;
				break;
			}
			++j;
			++k;
		} while (oneString[j] && secondString[k]);
		if (k > result)
			result = k;
	}
	return result;
}

void sumStrings(char *first, char *second, int overlap) {
	first[strlen(first) - overlap] = '\0';
	strcat(first, second);
	second[0] = '\0';
}	

int main() {
	int n, i, j, k, max, first, second, result;
	scanf("%d", &n);
	char **array = calloc(n, sizeof(char*));
	for (i = 0; i < n; ++i)	{
		array[i] = calloc(100, sizeof(char));
		scanf("%secondString", array[i]);
	}
	for (k = 1; k < n; ++k)	{
		for (i = 0, max = -1; i < n; ++i)
		for (j = 0; j < n; ++j)
		if (i != j && array[i][0] && array[j][0]) {
			int cur = overlapping(array[i], array[j]);
			if (cur > max)
				max = cur, first = i, second = j;
		}
		sumStrings(array[first], array[second], max);
		result = first;
	}
	printf("%d\n", (int)strlen(array[result]));
	for (i = 0; i < n; ++i)
		free(array[i]);
	free(array);
	return 0;
}