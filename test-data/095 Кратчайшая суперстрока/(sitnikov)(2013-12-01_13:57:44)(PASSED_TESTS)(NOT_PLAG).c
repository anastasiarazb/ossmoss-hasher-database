#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int k=100;

        //Функция для вычисления удлиннения строки

int cross(char *a, char *b) {
	int k, i, j,count;
	k=strlen(a)>strlen(b) ? strlen(b) : strlen(a);
	int lenA=strlen(a),lenB=(strlen(b));
	//printf("%d %d %d ",lenA,lenB,k);
	for (i=k-1;i>0;i--) {
		count=0;
		for (j=0;j<i;j++) {
			if (a[lenA-i+j]==b[j]) count++;
		}
		if (count==i) return lenB-count;
	}
	return lenB;
}
	
	//Реализуем размещения без повторений

void permut(int *N, int n, int *per, int len, int matr[len][len], char str[len][256]) {
	int i,j,sum=0;
	if (n==0) {
		//for(i=0;i<len;i++) printf("%d ",per[i]);
		//printf("\n");
		sum=strlen(str[per[0]]);
		for (j=1;j<len;j++) sum=sum+matr[per[j-1]][per[j]];
		//printf("%d\n", sum);
		//printf("%d ",k);
		if (sum<k) k=sum;
		//printf("%d ",k);
		
	}
	else {
		for(i=0;i<len;i++) {
			if (N[i]!=-1) {
				per[len-n]=N[i];
				N[i]=-1;
				permut(N,n-1,per,len, matr, str);
				N[i]=i;
			}
			
		}
	}
}


int main (){
  
	int n,i,j,sum=0;
	scanf("%d",&n);
	char str[n][256];
	for (i=0;i<n;i++) scanf("%s", str[i]);
	int mtr[n][n];
  
	//Cоздаем матрицу удлинннений
	
	for(i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			if (i==j) mtr[i][j]=-1;
			else mtr[i][j]=cross(str[i],str[j]);
		}
	}
	
	/*for(i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			if (j==n-1) printf("%d\n", mtr[i][j]);
			else printf("%d ",mtr[i][j]);
		}	
	}*/
	
	int N[n], per[n];
		 for(i=0;i<n;i++) {
			N[i]=i;
		 }	
	
	permut(N,n,per,n,mtr,str);
	printf("%d ",k);
  
	return 0;
}