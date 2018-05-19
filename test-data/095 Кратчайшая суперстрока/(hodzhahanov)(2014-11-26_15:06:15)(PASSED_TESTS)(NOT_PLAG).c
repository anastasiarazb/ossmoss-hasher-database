

#define _CRT_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int overlap(char* , char*);

void concat(char*, char*, int);

int main()
{
  int n, i,e, w = 0;
  scanf("%d ", &n);
  char A[n][100];
  for ( i = 0; i < n; i++)
    gets(A[i]);
  int k, j, max, a, b, c, res;
  for (k = 1; k < n; k++) {
    for (i = 0, max = -1; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (i != j && A[i][0] != NULL && A[j][0] != NULL) {
	  c = overlap(A[i], A[j]);
	  if (c > max) {
	    max = c;
	    a = i;
	    b = j;
	  }
	}
      }
    }
    concat(A[a], A[b], max);
    res = a;
  }
  int len = strlen(A[res]);
  printf("%d\n", len);
 // puts(A[res]);
  return 0;
}

int overlap(char* A, char* B) // B наложение на А
{
  int a = strlen(A);
  int b = strlen(B);
  int i,t,z, e = 0;
  for( i = 0; i < a; i++) {
    z = i;
    t = 0;
    while ( A[z] == B[t] && t < b && z < a ) {
      z++;
      t++;
    if ( t > e && A[z] == '\0') e = t;
    }
  }
  return e;
}
    
void concat(char* A, char* B, int size)
{
  A[strlen(A) - size] = '\0';
  strcat(A, B);
  B[0] = NULL;
}