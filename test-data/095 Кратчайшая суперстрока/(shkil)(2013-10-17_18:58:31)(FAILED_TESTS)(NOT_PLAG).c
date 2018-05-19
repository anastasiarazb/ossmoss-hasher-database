#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char permut(char **q, int n){
char **a;
int i;
a=(char**)malloc(n*sizeof(char*));
for (i=0;i<n;i++){
a[i]=(char*)malloc(255*sizeof(char));
a[i]=q[i];}
for (i=0; i<n; i++) printf ("%s\n", a[i]);
for (i=0; i<n; i++) free (a[i]);
free (a);
}

int main () {
char **a;
int i, n;
scanf ("%d\n", &n);
a=(char**)malloc(n*sizeof(char*));
for (i=0;i<n;i++) 
a[i]=(char*)malloc(255*sizeof(char));
for (i=0; i<n; i++)
  gets(a[i]);
permut (a, n);
for (i=0; i<n; i++) free (a[i]);
free (a);
  return 0;
}