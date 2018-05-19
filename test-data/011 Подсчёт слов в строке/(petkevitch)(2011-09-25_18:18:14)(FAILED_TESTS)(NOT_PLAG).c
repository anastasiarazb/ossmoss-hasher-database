#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Maxlenth 1000000

int wcount(char *s)
{
  int n, i, k;
  i=0;
  n=0;
  if (s[0]!=' ')
    k=0;
    else
      k=1;
  do {
    if (s[i]!=' ')
      k=0;
    if ((s[i]==' ') & (k==0))
      {
       n++;
       k=1;
      }
    i++;
  } while (i!=strlen(s));
  if (k==0)
  n++;
  return n;
}

int main(int argc , char ** argv)
{
  char S[Maxlenth];

  gets(S);

  if (strlen(S)>0)
    printf("%d\n",wcount(S));
    else
      printf("the line is empty - 0");

  return 0;
}
