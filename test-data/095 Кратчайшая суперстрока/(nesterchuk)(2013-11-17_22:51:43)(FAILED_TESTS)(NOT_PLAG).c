#include <stdio.h>
#include <string.h>


/* Функция для вычисления пересечений строк */
int cut(char *a, char *b) {
        int i, j, len=strlen(a), n=0;
	for (i=0; i<len; i++) {
		if (a[i]==b[0]) {
			for (j=0; j+i<len; j++) {
				if (a[j+i]!=b[j]) {
					n=0;
					break;
				}
				n++;
			}
		}
		if (n!=0) break;
	}
	
	return n;
}

/*Функция считает сумму всех пересечений строк */
int summat(int mat[10][10], int n, int *numb) {
	int i, sumt=0;
	for (i=0; i<n-1; i++) sumt = sumt + mat[numb[i]][numb[i+1]];
	return sumt;
}


/* Алгоритм Нарайаны: */
int NextPerm (int *a, int n) {
	int i, k, t, tmp;
	for (k = n - 2; a[k] > a[k + 1] && k >= 0; k--);
	if (k == -1)
		return 0;
	for (t = n - 1; (a[k] > a[t]) && (t >= k + 1); t--);
	tmp = a[k], a[k] = a[t], a[t] = tmp;
	for (i = k + 1; i <= (n + k)/2; i++) {
		t = n + k - i;
		tmp = a[i], a[i] = a[t], a[t] = tmp;
	}
	return i;
}



int main()
{
	int n=0, i, j, len, sum=0, numb[10]={0,1,2,3,4,5,6,7,8,9}, min, k, t, l=0;
	char str[11][20];
	int mat[10][10]={{0}};
	scanf("%d\n", &n);
	for (i=0; i<n; i++) gets(str[i]);
        /* Матрица пересечений */
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) mat[i][j]=cut(str[i], str[j]);
	}
	
	for (i=0; i<n; i++) sum=sum+strlen(str[i]);
	min = sum - summat(mat, n, numb);
	
        /* Работаем с перестановками */
	do {
		len = sum - summat(mat, n, numb);
		if (len<min) min=len;
	} while (NextPerm (numb, n));
	
	printf("%d\n", min);
	return 0;
}