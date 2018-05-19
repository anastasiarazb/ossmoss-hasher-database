
#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
  int i=0, k=0;
  if (s[0]==' ') {
    START:
    while (s[i]==' ')
      i++;
    if (s[i]='\0')
      return k;
    while (s[i]!=' ')
      i++;
    k++;
    if (s[i]='\0')
      return k;
    else
      goto START;
  }
  else {
    do {
      while (s[i]!=' ')
        i++;
      k++;
      while (s[i]==' ')
	i++;
    } while (s[i]!='\0');
    return k;
  }
}

int main(int argc, char **argv)
{
  char a[200];
  int b;
  gets(a);
  b=wcount(a);
  printf("%d\n", b);
  return 0;
}