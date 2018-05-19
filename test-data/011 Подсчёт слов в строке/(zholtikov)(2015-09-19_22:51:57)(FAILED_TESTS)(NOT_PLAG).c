#include <string.h>
#include <stdio.h>

int main()
{

int wcount(char *s)
{

  char st [255];
  printf("введите строку ");
  gets(st);
  int n,i,k;
  k= strlen(st);
  n=0;
  for (i=0; i< k-1;i++)
    if ((st[i]==' ') && (st[i+1]!=' '))
      n=n+1;
    if (st[0]!=' ')
      n=n+1;

  printf("%d\n", n);
}
return 0;
}
