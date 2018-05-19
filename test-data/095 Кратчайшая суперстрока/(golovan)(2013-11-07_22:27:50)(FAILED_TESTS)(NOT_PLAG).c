#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maxcount, maxlen;

void Permut(char **s , unsigned short n) 
{
     unsigned short k[n],i;
    for (i=0; i<n; i++) k[i]=-1;
    PRec(s ,1023, n, n, k, 0, 0);
}

void PRec(char **s, unsigned short Q, unsigned short count, unsigned  short m, unsigned  short *p, unsigned  short pc, unsigned  short elem)
{
     unsigned short i, k[pc+1];
    int j;
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

void intersect(char *s1, char *s2)
{
     unsigned short m=strlen(s1), n=strlen(s2), c, count, i;
    if (m>n) c=m-n+1;
    else c=1;
    
    char p[n+1];
    p[0]='\0';
    for (i=c; i<m; i++) {
       strncpy(p, s2, m-i);
       p[m-i]='\0';
       if (strcmp(p, &s1[i])==0) {
//	  printf("Concat: %s + %s ", s1, s2);
	  strcat(s1, &s2[m-i]);
//	  printf("(%d)\n", strlen(s1));
//	  printf("  %s\n", s1);
	  return;
       }
    }
    strcat(s1, s2);
}

int getsuper(char **s,  unsigned short *q, unsigned short n, int mlen)
{
    short i;
    char st[mlen];
    st[0]='\0';
    strcat(st, s[q[0]]);
    for (i=1; i<n; i++) {
      intersect(st, s[q[i]]);
      if (strlen(st)>=maxcount) 
	 return maxcount;
    }
    return strlen(st);
}

int main() {
  unsigned short i, n,c;
  scanf("%d ", &n);
  char *s[n];
  for (i=0; i<n; i++) {
    s[i]=(char*)malloc(256);
    scanf("%s", s[i]);
    maxlen+=strlen(s[i]);
  }
  maxcount=maxlen;
  Permut(s, n);
  printf("%d\n", maxcount);
  for (i=0; i<n; i++) free(s[i]);
  return 0;
}