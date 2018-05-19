#include <stdio.h>
#include <string.h>


int fac(int n)
{
        int i, sum=1;
        for (i=2; i<=n; i++) sum=sum*i;
	return sum;
}


int cut(char *a, char *b) {
	int i, enter=0, len=strlen(a);
	for (i=0; i<20; i++) {
		if (a[len-i-1]==b[i]) enter++;
		else break;
	}
	return enter;
}


void swap(int a, int b)
{
	int tmp=a;
	a=b;
	b=tmp;
	return;
}

int summat(int mat[10][10], int n, int *numb) {
	int i, sumt=0;
	for (i=0; i<n-1; i++) sumt = sumt + mat[numb[i]][numb[i+1]];
	return sumt;
}


int main()
{
	int n, i, j, len, sum=0, numb[10]={0,1,2,3,4,5,6,7,8,9}, min;
	char str[11][20]={{0}};
	int mat[10][10]={{0}};
	scanf("%d", &n);
        for (i=0; i<n; i++) gets(str[i]);
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			mat[i][j]=cut(str[i], str[j]);
		}
	}
	for (i=0; i<n; i++) sum=sum+strlen(str[i]);
	min = sum - 2*summat(mat, n, numb) + 1;
	for (j=1, i=0; j<fac(n); j++, i++) {
		if (i>=n) i=0;
		if (i==n-1) swap(numb[i], numb[0]);
		else swap(numb[i], numb[i+1]);
		len = sum - 2*summat(mat, n, numb) + 1;
		if (len<min) min=len;
	}
	printf("%d\n", min);
	return 0;
}