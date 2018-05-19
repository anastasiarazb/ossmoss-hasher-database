 /*Алгоритм найден в интернете*/
#include <stdio.h>
#include <string.h>
int overlap(char *s1,char *s2) /*Находим длину суффиксно-префиксного совпадения двух строк*/ 
{
        int state=0, i=0, overlap=0;
	unsigned long l1;
	l1=strlen(s1);
	for (i=0;i<l1;i++){
		if (s1[i]==s2[overlap]){
			state = 1;
			overlap++;
		}
		else{
			if(state == 1){
				state = 0;
				i-=overlap;
				overlap=0;
			}
		}
	}
	return overlap;
}
 
int main(int argc, char **argv)
{
	int n, i, j, k, f, L=0, Max, Min, jmax, kmax;
	scanf("%d ", &n);
	int Matrix[n][n], M[n];    
	char strs[n][1000];
	for (i = 0; i < n; i++)
		scanf("%s", &strs[i]);
	for (i=0;i<n;i++){
        	for (j=0;j<n;j++){
            		Matrix[i][j]=overlap(strs[i],strs[j]);
            		if (i==j) 
				Matrix[i][j]=-1;
        	} /*Составляем матрицу суффиксно-префиксного совпадения*/ 
    	}
	/*Реализуем 4-приближенный алгоритм нахождения кратчайшей суперстроки*/	
	for (i=0;i<n;i++){
        	Max=0;
		for (j=0;j<n;j++){
            		for (k=0;k<n;k++){
                		if(Matrix[j][k]>Max){
					jmax=j;
					kmax=k;
					Max=Matrix[j][k];
				}
			}
		}
		for (f=0;f<n;f++){
            		Matrix[f][kmax]=-1;
			Matrix[jmax][f]=-1;
		}
		M[i]=Max;
	} /* Наша задача сводится к задаче "о назначениях". Только что был создан массив максимумов матрицы совпадения, где индексами массива служат номера столбцов матрицы совпадения.*/
	/* Покрываем эту матрицу циклами */
	for(i=0;i<n;i++){
		L+=strlen(strs[i]);
		Max += M[i];
	}
	Min=M[0];
	for(i=0;i<n;i++){		
		if(M[i]<Min)		
			Min = M[i];
	}
	Max-=Min;
	printf("%d\n",L-Max);
	return 0;
}