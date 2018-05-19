#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 256

int SuperStr(int n, char **str);
int Compare(char *a, char *b);

int main(){
        int i, n;
	scanf("%d\n", &n);
	char **str = (char**)malloc(n*sizeof(char*));
	for (i = 0; i < n; i++){
		str[i] = (char*)calloc(STR_SIZE, sizeof(char));
		gets(str[i]);
	}
	SuperStr(n, str);
	return 0;
}
int SuperStr(int n, char **str){
	int i, sk, sl;
	int **arr = (int**)calloc(n, sizeof(int*));
	for (i = 0; i < n; i++)
		arr[i] = (int*)calloc(n, sizeof(int));

	for (sk = 0; sk < n; sk++){
		for (sl = 0; sl < n; sl++){
			if (sk == sl)
				continue;
			else{
				arr[sk][sl] = Compare(str[sk], str[sl]);
			}
		}
	}
	for (sk = 0; sk < n; sk++){
		for (sl = 0; sl < n; sl++){
			printf("%d ", arr[sk][sl]);
			printf("\n");
		}
	}
	return 0;
}
int Compare(char *a, char *b){
	int i, j;
	int len_a = strnlen(a, STR_SIZE),
	len_b = strnlen(b, STR_SIZE);
	if (len_a > len_b){
		for (i = len_a-(len_b-1), j = 0; i <= len_a-1; i++, j--){
			if (!strncmp(a+i, b, len_b-1+j)){
				return len_b-1+j;
			}
		}
	}
	else{
		for (i = 1, j = 0; i <= len_a-1; i++, j--){
			if (!strncmp(a+i, b, len_a-1+j)){
				return len_a-1+j;
			}
		}
	}
}