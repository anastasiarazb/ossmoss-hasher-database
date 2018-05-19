#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int LM();
int comp(int, int);
void Permut(int*, int, int, int);
void permute(int Q[], int i, int m, int p);

int compare[10][10];//Сравним каждую строку с каждой на количество совпад элементов справа и слева
int n, alllen;//Сумма всех длин,а потом и со сдвигом
char strs[10][25];

int main(){
        int i, j;
	alllen = 0;
	scanf("%d", &n);
	gets(strs[0]);
	i = 0;
	while (i < n){
		gets(strs[i]);
		alllen += strlen(strs[i]);
		++i;
	}
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++)
		if (i != j){
			compare[i][j] = comp(i, j);// i -строка ,чей конец мы пытаемся впихнуть в начало j-той строки Check(i, j); 
		}
		else compare[i][j] = 0;
	}
	int Q[10];
	//printf("%d\n", alllen);
	for (i = 0; i < n; i++)Q[i] = i;
	//Permut(Q, n, alllen, 0);
	alllen -= LM();
	//for (i = 0; i < n; i++){
	//for (j = 0; j < n; j++)
	//printf("%d ", compare[i][j]);
	//printf("\n");
	//}
	printf("%d", alllen);
	//getchar(); getchar(); getchar();
	return 0;
}

int LM(){
	int i, j, max[10], min, sum;//n
	min = alllen;
	for (i = 0; i < n; i++)max[i] = 0;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++)
			if (compare[i][j] > max[i]) max[i] = compare[i][j];
	}
	sum = 0;
	for (i = 0; i < n; i++){
		sum += max[i];
		//printf("%d\n", max[i]);
		if (max[i] < min)min = max[i]; 
	}
	sum -= min;
	return sum;
}

int comp(int i, int j){
	int a, b, leni, lenj;
	a = 1;
	b = 0;
	leni = strlen(strs[i]);
	lenj = strlen(strs[j]);
	if (lenj < leni) b = leni - lenj;
	while (a < leni){//Сравниваем строки,изначально считая что i входит в j на len-1 элемент,и продвигаемся вниз на 1
		while (strs[i][a + b] == strs[j][b]){
			b += 1;
			if ((a + b) == leni) return b;
		}
		a += 1;
		b = 0;
	}
	return b;
}

void Permut(int* Q, int m, int p, int count){
	int i;
	if (((count == n - 1) || (m == 0)) && (p < alllen)) alllen = p;
	else
	for (i = 0; i < n; i++){
		if (Q[i] != 10){
			Q[i] = 10;
			Permut(Q, m - 1, p - compare[i][n - m], count + 1);
			Q[i] = i;
		}
	}
}