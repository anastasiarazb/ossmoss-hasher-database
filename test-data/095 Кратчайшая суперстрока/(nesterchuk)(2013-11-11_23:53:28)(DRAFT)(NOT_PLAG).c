#include <stdio.h>
#include <string.h>


int fac(int n)
{
        int i, sum=1;
        for (i=2; i<=n; i++) sum=sum*i;
	return sum;
}



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


void swap(int *numb, int i, int j)
{
	int tmp=numb[i];
	numb[i]=numb[j];
	numb[j]=tmp;
	return;
}

int summat(int mat[10][10], int n, int *numb) {
	int i, sumt=0;
	for (i=0; i<n-1; i++) sumt = sumt + mat[numb[i]][numb[i+1]];
	return sumt;
}


int main()
{
	int n, i, j, len, sum=0, numb[10]={0,1,2,3,4,5,6,7,8,9}, min, k;
	char str[11][20]={"caacccca", "accaacccc", "cabaccaac"};
	int mat[10][10]={{0}};
	n=3;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			mat[i][j]=cut(str[i], str[j]);
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	for (i=0; i<n; i++) sum=sum+strlen(str[i]);
	min = sum - summat(mat, n, numb);
	printf("\n%d  ", min);
	for (k=0; k<n; k++) printf("%s|", str[k]);
	for (j=1, i=0; j<fac(n); j++, i++) {
		if (i>=n) i=0;
		if (i==n-1) swap(numb,i,0);
		else swap(numb,i,i+1);
		len = sum - summat(mat, n, numb);
		printf("\n%d  ", len);
		for (k=0; k<n; k++) printf("%s|", str[numb[k]]);
		if (len<min) min=len;
	}
	printf("\n%d\n", min);
	return 0;
}