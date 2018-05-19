#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maxcount, maxlen, inter[10][10];

void Permut(char **s ,int n) 
{
    int k[n],i;
    for (i=0; i<n; i++) k[i]=-1;
    PRec(s ,1023, n, n, k, 0, 0);
}

void PRec(char **s, unsigned short Q, int count, int m, int *p, int pc, int elem)
{
    int i, k[pc+1], j;
    for (i=0; i<pc; i++) k[i]=p[i];
    if (pc>0) k[pc-1]=elem;
    if (m==0) {
        j=getsuper(s, k, pc, maxlen);
	if (j<maxcount) maxcount=j;
    } else {
	for (i=0; i<count; i++)
	    if (Q & (1<<i))
	      PRec(s, Q-(1<<i), count, m-1, k, pc+1, i);
    }
}

int intersect(char **s, int a, int b)
{
    if ((inter[a][b])!=-1) return inter[a][b];
    else {
        int m=strlen(s[a]), n=strlen(s[b]), i, j, k, c;
	if (m>n) c=m-n+1;
	else c=1;
	for (i=c; i<m; i++) {
	      k=1;
	      for (j=m-i-1; j>=0; j--) {
		  if (s[b][j]!=s[a][i+j]) {
		    k=0;
		    break;
		  }
	      }
	      if (k) {
		  inter[a][b]=m-i;
		  return m-i;
	      }
	}
	inter[a][b]=0;
	return 0;
    }
}

int getsuper(char **s, int *q, int n, int mlen)
{
    int i, sum=strlen(s[q[0]]);
    for (i=1; i<n; i++) {
      sum=sum+strlen(s[q[i]])-intersect(s, q[i-1], q[i]);
      if (sum>=maxcount) 
	 return maxcount;
    }
    return sum;
}

int main() {
  int i, j, n,c;
  scanf("%d ", &n);
  char *s[n];
  for (i=0; i<n; i++) {
    s[i]=(char*)malloc(256);
    scanf("%s", s[i]);
    maxlen+=strlen(s[i]);
  }
  for (i=0; i<n; i++) {
     for (j=0; j<n; j++)
        inter[i][j]=-1;
  }
maxcount=maxlen;
  Permut(s, n);
  printf("%d\n", maxcount);
  for (i=0; i<n; i++) free(s[i]);
  return 0;
}