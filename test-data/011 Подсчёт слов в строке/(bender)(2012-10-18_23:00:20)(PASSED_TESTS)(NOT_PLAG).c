
#include <stdio.h>
#include <string.h>

int max = 1000;

int wcount(char *s)
{
  int i,k = 0;
  
  for (i = 0;i < strnlen(s,max);i++)
  {
    if ((i == 0) && (s[i] != ' ')) k++;
    else if ( (s[i] != 0) && (s[i-1] == ' ') && (s[i] != ' ') ) k++;
  }
  
  return k;
}

int main()
{
  char s[max];
  
  gets(s);
  
  printf("%d", wcount(s) );
  
  return 0;
}