#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len = 0;
int n = 0;

void MatrBuilder(char **string, int **arr)
{
        int i = 0;
	for (i = 0; i < n; i++) {
		int j = 0;
		for (j = 0; j < n; j++) {
			if (i == j) *(*(arr + i) + j) = 0;
			if (i != j) *(*(arr + i) + j) = DifferenceLines(*(string + j), *(string + i));
		}
	}
}

int DifferenceLines(char *string1, char *string2)
{
	int k = 0;
        int minlength = MinLen(string1, string2);
	int i = 0;
	int StrPs1 = strlen(string2);
	for (i = 1; i < minlength; i++) if(strncmp(StrPs1 + string2 - i, string1, i) == 0) k = i;
	return k;
}

int MinLen(char *string1, char *string2)
{
	int strs1 = strlen(string1);
	int strs2 = strlen(string2);
	if (strs2 > strs1) return strs1;
	else return strs2;
}


int Maximum(int *s1, int *s2, int **arr)
{
        int Max = **arr;
        int i = 0;
	for (i = 0; i < n; i++) {
		int j = 0;
		for (j = 0; j < n; j++) {
			if(*(*(arr + i) + j) > Max) {
				*s1 = i;
				*s2 = j;
				Max = *(*(arr + i) + j);
			}
		}
	}
	return Max;
}

int main(int argc, char **argv)
{
	int s1 = 0, s2 = 0;
        int Max = 0;
	scanf("%d\n",&n);
	int **arr;
	arr = (int**)malloc(sizeof(int*)*n);
	char **string;
	string = (char**)malloc(sizeof(char*)*n);
	int i = 0;
	for (i = 0; i < n; i++) {
		*(arr + i) = (int *)calloc(n, sizeof(int));
		*(string + i) = (char *)calloc(255, sizeof(char));
	}
	int StrS = 0;
	int j = 0;
	int k = 0;
	for (j = 0; j < n; j++) {
		gets(string[j]);
		StrS = strlen(string[j]);
		k = k + StrS;
	}
	MatrBuilder(string, arr);
	i = j = 0;
	Max = Maximum(&s1, &s2, arr);
	for (j = 0; Max != 0 && (j < n - 1); j++) {
		len = len + Max;
		for (i = 0; i < n; i++) {
			*(*(arr + s1) + i) = 0;
			*(*(arr + i) + s2) = 0;
		}
	Max = Maximum(&s1, &s2, arr);
	}
	k = k - len;
	printf("%d",k);
	for (i = 0; i < n; i++) free(arr[i]);
	for (i = 0; i < n; i++) free(string[i]);
	free(arr);
	free(string);
	return 0;
}