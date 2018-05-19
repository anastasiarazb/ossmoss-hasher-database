#include <stdio.h>
#include <string.h>
#include <stdlib.h>

short maxcount, maxlen;

void Permut(char **s ,short n) 
{
    short k[n];
    memset(k, 0, n);
    PRec(s ,1023, n, n, k, 0, 0);
}

void PRec(char **s, unsigned short Q, short count, short m, short *p, short pc, short elem)
{
    short i, k[pc+1], j;
    for (i=0; i<pc; i++) k[i]=p[i];
    if (pc>0) k[pc-1]=elem;
    if (m==0) {
        j=getsuper(s, k, count, maxlen);
	if (j<maxcount) maxcount=j;
    } else {
	for (i=0; i<count; i++)
	    if (Q & (1<<i))
	      PRec(s, Q-(1<<i), count, m-1, k, pc+1, i);
    }
}

void intersect(char *s1, char *s2)
{
    short i, j=0, len1=strlen(s1), len2=strlen(s2), c, r2=-1;
    char *r1, b[len2+1];
    c=(len1 > len2 ? len2 : len1);
    r1=s1+len1;
    b[0]='\0';
    for (i=0; i<c; i++) {
      r1-=1;
      r2+=1;
      strncpy(b, s2, r2+1);
      b[r2+1]='\0';
      if (strcmp(b, r1)==0) 
	  j=r2+1;
    }
    b[0]='\0';
    strcpy(b, &s2[j]);
    b[len2-j+1]='\0';
    strcat(s1, b);
}

short getsuper(char **s, short *q, short n, short mlen)
{
    short i;
    char st[mlen];
    st[0]='\0';
    for (i=0; i<n; i++) {
      intersect(st, s[q[i]]);
    }
    return strlen(st);
}

int main() {
  short i, n,c;
  scanf("%sd ", &n);
  char *s[n];
  for (i=0; i<n; i++) {
    s[i]=(char*)malloc(256);
    scanf("%s", s[i]);
    maxlen+=strlen(s[i]);
  }
  maxcount=maxlen;
  Permut(s, n);
  printf("%sd\n", maxcount);
  for (i=0; i<n; i++) free(s[i]);
  return 0;
}