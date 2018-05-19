#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s)
{
  int word, i;
  word=0;
  if (strnlen(s, 1000)==0) 
    return 0;
  else
  {
    if (s[0]==' ')
      word=0;
    else
    word=1;
    i=0;
    while (i<strnlen(s, 1000)-1) 
    {
      if ((s[i]==' ') && (s[i+1]!=' '))
      word++;
      i++;
    }
  return word;
  }
}
 
 
int main()
{
  char s[1000];
  gets(s);
  printf("%d\n", wcount(s));
  return 0;
} 