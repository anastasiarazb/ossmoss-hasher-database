#include <string.h>
#include <stdio.h>

int wcount(char *s) 
{ 
  int i=0,n,x=0;
  n=strlen(s); 
  if (s[0]!=' ')
  {
    x++;
    while (s[i]!=' ')
      i++;
  } 
  
  for (i; i<n-1; i++)
  {
   if ((s[i]==' ')&&(s[i+1]!=' '))
     x++;
  }
  return x;
}

int main()
{
  char s[255];
  gets(s); 
  printf("%d\n",wcount(s));  
  return 0;
}