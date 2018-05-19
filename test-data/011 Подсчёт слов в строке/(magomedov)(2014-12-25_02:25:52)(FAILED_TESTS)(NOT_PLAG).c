int wcount(char *s)
{
  int i = 0, slovo, count = 0;
  while(s[i]== ' ' && s[i]!='\0')
    i++;
  slovo = 0;
  while(s[i]!='\0')
  {
    if(s[i]!=' ' && slovo == 0)
    {
      slovo = 1;
      count++;
    }
    else  if(s[i]==' ')
      slovo = 0;
    i++;
  }
  printf("%d\n", count);
  return count;
 
}

#include <stdio.h>

void main()
{
  int n = 0, count = 0;
  char s[n]; 
  gets(s);
  wcount(s);
}