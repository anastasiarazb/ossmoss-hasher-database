#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int fact(int n)
{
        return n ? n * fact(n - 1) : 1;
}

int swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int main(int argc, char const *argv[])
{
	int n, i;
	scanf("%d ", &n);

	char **strings = (char**)malloc(n * sizeof(char*)), **matches = (char**)malloc(n * sizeof(char*));
	int indexs[n];
	for (i = 0; i < n; ++i) {
		indexs[i] = i;
		matches[i] = (char*)malloc(n * sizeof(char));
		strings[i] = (char*)malloc(100 * sizeof(char));
		gets(strings[i]);
	}

	int k = 0, j; 
	for (i = 0; i < n; ++i) { // матрица из длины совпадений префикса i-ой строки с суффиксом j-ой
		for (j = 0; j < n; ++j) {
			matches[i][j] = 0;
			while (strings[j][strlen(strings[j]) - k - 1] == strings[i][k++]) {
				matches[i][j]++;
			}
			k = 0;
		}
	}

	int sumOfLengths = 0, minLength = 0, length;

	for (i = 0; i < n - 1; ++i) {
		sumOfLengths += strlen(strings[i]);
		minLength += strlen(strings[i]) - matches[i + 1][i];
	}
	sumOfLengths += strlen(strings[i]);

	while (k++ < fact(n) - 1) { // расчёт перестановок индексов строк; n! - 1, т.к. первая перестановка уже рассмотрена
		for (i = n - 2; indexs[i] >= indexs[i + 1] && i >= 0; --i); // находим первый с конца элемент, который меньше последующего

		for (j = n - 1; indexs[j] <= indexs[i]; --j); // находим первый элемент, больший выбранного
		
		swap(indexs + i, indexs + j); // меняем их местами

		for (++i, j = n - 1; i < j; ++i, --j) swap(indexs + i, indexs + j); // массив переписывается в обратном порядке

		length = sumOfLengths;
		for (i = 0; i < n - 1; ++i) length -= matches[indexs[i + 1]][indexs[i]];
		if (length < minLength) minLength = length;
	}

	printf("%d\n", minLength);

	for (i = 0; i < n; ++i) {
		free(matches[i]);
		free(strings[i]);
	}
	free(matches);
	free(strings);
	
	return 0;
}