#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void concat(char* A, char* B, int size);
int help(char* A, char* B) ;
int Max = 2500;
void swap(int *x, int *y)
{
    int h;
    h = *x;
    *x = *y;
    *y = h;
}
void por(int *a, int l, int r, char** S, char* str)
{
   int i, j, len;
   if (l == r) {
        strcat(str, S[a[0]]);
      for(j = 1; j < r + 1; j++)
        concat(str, S[a[j]], help(str, S[a[j]]));
        len = strlen(str);
        if ( Max > len ) Max = len;
        memset(str, 0, 10*50);
   }
   else
   {
       for (i = l; i <= r; i++){
          swap((a + l), (a + i));
          permute(a, l + 1, r, S, str);
          swap((a + l), (a + i));
       }
   }
}
int help(char* A, char* B) 
{
  int a = strlen(A);
  int b = strlen(B);
  int i, t, z, e = 0;
  for( i = 0; i < a; i++) {
          z = i;
          t = 0;
    while((A[z] == B[t]) && (z < a) && (t < b)){
      z++;
      t++;
    if ((t > e) && (A[z] == '\0')) e = t;
    }
  }
  return e;
}
void concat(char* A, char* B, int size)
{
  A[strlen(A) - size] = '\0';
  strcat(A, B);
}
int main()
{
        int i, j;
        scanf("%d", &i);
        int* string = calloc(i,sizeof(int));
        for(j = 0; j < i; j++)
            string[j] = j;
        char** S = calloc(i, sizeof(char*));
        char* str = calloc(10 * 50,sizeof(char));
        for(j = 0; j < i; j++){
                S[o] = calloc(50,sizeof(char));
                scanf("%s", S[j]);
        }
    por(string, 0, i - 1, S, str);
    printf("%d\n", Max);
    return 0;
}