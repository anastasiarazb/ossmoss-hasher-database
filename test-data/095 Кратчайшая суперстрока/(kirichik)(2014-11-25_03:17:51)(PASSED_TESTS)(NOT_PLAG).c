#define IN 1/*Алгоритм найден в интернете*/
#define OUT 0
#include <stdio.h>
#include <string.h>
int overlap(char *s1,char *s2) /*Находим длину суффиксно-префиксного совпадения двух строк*/ 
{
        int state=OUT, i=0, overlap=0;
	unsigned long l1;
	l1=strlen(s1);
	while(i<l1){
		if (s1[i]==s2[overlap]){
			state = IN;
			overlap++;
		}
		else{
			if(state == IN){
				state = OUT;
				i-=overlap;
				overlap=0;
			}
		}
		i++;
	}
	return overlap;
}
 
 
int main(int argc, char **argv)
{
	int n, i, j, k, t=0, StrLen=0, Max=0, strmax, stlmax, Min;
	scanf("%d", &n);
	int Matrix[n][n], M[n];	
	char strs[n][1000];
	for (i = 0; i < n; i++)
        	scanf("%s", &strs[i]);
	/*Формиурем матрицу суффиксно-префиксных совпадений*/	
	for (i=0;i<n;i++){
        	for (j=0;j<n;j++){
			Matrix[i][j]=overlap(strs[i],strs[j]);
			if (i==j) Matrix[i][j]=-1;/*Элементы, в которых матрица совпадений содержит overlap одной и той же строки делаем "недоступными", т.к. overlap никогда не вернет значения "-1"*/
		}
	}
	for (i=0;i<n;i++){     	
		for (j=0;j<n;j++){
            		for (k=0;k<n;k++){
                		if(Matrix[j][k]>Max){
                    			strmax=j;
                    			stlmax=k;
                    			Max=Matrix[j][k];/*Находим максимальный на данной итерации элемент матрицы*/
                		}      		
			}   	
		}
        	for(t=0;t<n;t++){
        		Matrix[t][stlmax]=-1;/*Делаем строчку и столбец, в которых был найден максимальный на данной итерации элемент "недоступными"*/
        		Matrix[strmax][t]=-1;       	
		}
        	M[i]=Max;/*Создаем массив максимумов на каждой итерации*/
    		Max=0;
	}
	/*Собственно, вычисление длины суперстроки. Вопрос -- с какой строки начинать отсчет? Нужно просто минимизировать overlap первой и последней строки. В таком случае суперстрока получится самая короткая.*/	
	int SMax=0;	
	Min=M[0];	
	for(i=0;i<n;i++){
		StrLen+=strlen(strs[i]);
       		SMax += M[i];
        }
	for(i=0;i<n;i++){	
		if(M[i] < Min)
        	Min = M[i];
	}
	SMax-=Min;
	printf("%d\n",StrLen-SMax);
	return 0;
}