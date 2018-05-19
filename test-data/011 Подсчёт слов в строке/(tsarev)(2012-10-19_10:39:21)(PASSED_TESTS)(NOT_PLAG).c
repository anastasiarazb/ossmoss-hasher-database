
#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
  int i=0, k=0;
  if (s[0]==' ') {
    START:
    while (s[i]==' ')
      i++;
    if (s[i]=='\0')
      return k;
    while (s[i]!=' ') {
      if (s[i]=='\0')
        break;
      i++;
    }
    k++;
    if (s[i]=='\0')
      return k;
    else
      goto START;
  }
  if (s[0]!=' ') {
    if (s[0]=='\0')
      return 0;
    BEGIN:
    while (s[i]!=' ' && s[i]!='\0')
      i++;
    k++;
    if (s[i]=='\0')
      return k;
    while (s[i]==' ')
      i++;
    if (s[i]=='\0')
      return k;
    else
      goto BEGIN;
  }
}

int main(int argc, char **argv)
{
  char a[500];
  int b;
  gets(a);
  b=wcount(a);
  printf("%d\n", b);
  return 0;
}