#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 256

int SuperStr(int n, char **str);
int Compare(char *a, char *b);
void Swap(int *a, int *b);
void Reverse(int *P, int m);
void Antilex(int *P, int *strnel, int **arr, int m);

int Size, Min_result;

int main(){
        int i, n;
        scanf("%d\n", &n);
        Min_result = STR_SIZE*n;
	char **str = (char**)malloc(n*sizeof(char*));
	for (i = 0; i < n; i++){
		str[i] = (char*)calloc(STR_SIZE, sizeof(char));
		gets(str[i]);
	}
	printf("%d\n", SuperStr(n, str));
	for (i = 0; i < n; i++)
	  free (str[i]);
	free (str);
	return 0;
}
int SuperStr(int n, char **str){
	int i, sk, sl;
	//Массив с размерами строк
	int *strnel = (int*)calloc(n, sizeof(int));
	for (i=0; i < n; i++)
	  strnel[i] = strnlen(str[i], 256);
	//Массив пересечений
	int **arr = (int**)calloc(n, sizeof(int*));
	for (i = 0; i < n; i++)
		arr[i] = (int*)calloc(n, sizeof(int));
	for (sl = 0; sl < n; sl++){
		for (sk = 0; sk < n; sk++){
			if (sk == sl)
				continue;
			else{
				arr[sl][sk] = Compare(str[sl], str[sk]);
			}
		}
	}
	//Массив индексов. Их перестановка
	int *P = (int*)calloc(n, sizeof(int));
	for(i=0; i<n; ++i)
	  P[i] = i;
	Size = n;
	Antilex(P, strnel, arr, n-1);
	free (strnel);
	for (i = 0; i < n; i++)
	  free (arr[i]);
	free (arr);
	free (P);
	return Min_result;
}
int Compare(char *a, char *b){
	int i, j;
	int len_a = strnlen(a, STR_SIZE),
	len_b = strnlen(b, STR_SIZE);
	if (len_a > len_b){
		for (i = len_a-(len_b-1), j = 0; i <= len_a-1; i++, j--)
			if (!strncmp(a+i, b, len_b-1+j))
				return len_b-1+j;
	}
	else{
		for (i = 1, j = 0; i <= len_a-1; i++, j--)
			if (!strncmp(a+i, b, len_a-1+j))
				return len_a-1+j;
	}
	return 0;
}
void Swap(int *a, int *b){
  int t=*a;
  *a=*b;
  *b=t;
}

void Reverse(int *P, int m){
   int i=0;
   while (i < m)
     Swap(&P[i++], &P[m--]);
}

void Antilex(int *P, int *strnel, int **arr, int m){
  int i;

  if (m==0){
    int Pre_Min_result = 0, flag = 1;
    for(i=0; i<Size-1; i++){
      Pre_Min_result += strnel[P[i]]-arr[P[i]][P[i+1]];
      if (Pre_Min_result+strnel[P[i+1]] > Min_result){//сокращаем время работы
	flag = 0;
	break;
      }
    }
    if (flag){
      Pre_Min_result += strnel[P[i]];
      if (Min_result > Pre_Min_result)
	Min_result = Pre_Min_result;
    }
  }
  else{
    for (i=0; i<=m; i++){
      Antilex(P, strnel, arr, m-1);
      if (i<m){
        Swap(&P[i], &P[m]);
        Reverse(P, m-1);
      }
    }
  }
}