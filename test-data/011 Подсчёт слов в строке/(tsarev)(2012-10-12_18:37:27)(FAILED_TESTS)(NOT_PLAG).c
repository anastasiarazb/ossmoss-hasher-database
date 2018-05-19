
#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
  int i=0, k=0;
  if (s[0]=='\0')
          return 0;
  if (s[1]=='\0') {
	  if (s[0]==' ')
		  return 0;
	  else
		  return 1;
  }
  if (s[0]==' ') {
    for (i=1; s[i]!='\0'; i++) {
	    if ((s[i]==' ' && s[i-1]!=' ')||(s[i]!=' ' && s[i+1]=='\0'))
		    k++;
    }
    return k;
  }
  if (s[0]!=' ') {
    do {
      while (s[i]!=' ' && s[i]!='\0')
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