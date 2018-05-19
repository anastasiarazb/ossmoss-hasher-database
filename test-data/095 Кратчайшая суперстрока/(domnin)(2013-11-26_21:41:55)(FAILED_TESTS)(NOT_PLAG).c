#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int comp(int, int);
void Permut( int, int, int);

int compare[10][10];//Сравним каждую строку с каждой на количество совпад элементов справа и слева
int n, alllen, result;//Сумма всех длин,а потом и со сдвигом
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
	result = alllen;
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++)
		if (i != j){
			compare[i][j] = comp(i, j);// i -строка ,чей конец мы пытаемся впихнуть в начало j-той строки 
		}
		else compare[i][j] = 0;
	}
	//printf("%d\n", alllen);
	for (i = 1; i < n; i++)Permut(alllen, 1, compare[0][i]);
	/*for (i = 0; i < n; i++){
		for (j = 0; j < n; j++)
			printf("%d ", compare[i][j]);
		printf("\n");
	}*/
	printf("%d", result);
	getchar(); getchar(); getchar();
	return 0;
}

int comp(int i, int j){
	int a, b, leni, lenj;
	a = 1;
	b = 0;
	leni = strlen(strs[i]);
	lenj = strlen(strs[j]);
	if (lenj < leni) b = leni - lenj;
	while (a < leni){//Сравниваем строки,изначально считая что i входит в j на len-1 элемент,и продвигаемся вниз на 1
		while (strs[i][a+b]==strs[j][b]){
			b += 1;
			if ((a + b) == leni) return b;
		}
		a += 1;
		b = 0;
	}
	return b;
}


void Permut( int res, int count, int min){
	int i;
	if (count == n){
		if ((res + min) < result) result = res + min;
	}
	else{
		for (i = 0; i < n; i++){
			if ((i != count)&&(min>compare[count][i])) Permut(res - compare[count][i], count + 1, compare[count][i]);
			else Permut(res - compare[count][i], count + 1, min);
		}
	}
}