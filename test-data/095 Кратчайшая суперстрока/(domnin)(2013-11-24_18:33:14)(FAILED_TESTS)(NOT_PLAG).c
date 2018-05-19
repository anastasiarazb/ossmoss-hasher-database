#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int comp(char*, char*, int, int);
void Permut(int* Q, int m, int p);

int compare[10][10];//Сравним каждую строку с каждой на количество совпад элементов справа и слева
int n, alllen;//Сумма всех длин,а потом и со сдвигом
char **strs;

int main(){
        int i, j;
	alllen = 0;
	scanf("%d\n", &n);
	strs = (char**) calloc(n, sizeof(char*));
	i = 0;
	while (i < n){
		strs[i] = (char*) malloc(25);
		gets(strs[i]);
		alllen += strlen(strs[i]);
		++i;
	}
	for (i = 0; i < 10; i++)for (j = 0; j < 10; j++)compare[i][j] = 0;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++)
		if (i == j) compare[i][j] = 0;
		else compare[i][j] = comp(strs[i], strs[j], strlen(strs[i]) - 1, strlen(strs[j]) - 1);
	}
	int Q[10];
	for (i = 0; i < n; i++)Q[i] = i;
	Permut(Q, n, alllen);
	printf("%d", alllen);
	return 0;
}

void Permut(int* Q, int m, int p){
	int i;
	if ((m == 0)&&(p < alllen)) alllen = p;
	else
	for (i = 0; i < n; i++){
		if (Q[i] != 10){
			Q[i] = 10;
			Permut(Q, m - 1, p - compare[n - m][i]);
			Q[i] = i;
		}
	}
}

int comp(char* str1, char* str2,int len1,int len2){
	int i;
	for (i = 0; (str1[len1 - i] == str2[i])&&(i < len1)&&(i < len2); i++);
	return i;//Возвращает кол-во совпадающих букв
}