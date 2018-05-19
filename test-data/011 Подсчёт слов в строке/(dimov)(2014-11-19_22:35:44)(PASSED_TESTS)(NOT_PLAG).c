#include <stdlib.h> 
# include <stdio.h>
int wcount(char *s) 
{ 
  int i,counter=0,flag=0;
  for(i=0;s[i]!='\0';i++)
      if(s[i]==' ')flag=0;
          else if (!(flag)){
              counter++;
	      flag=1;
	  }
  return counter;
} 
int main (int argc, char **argv)
{
  char s[10000],end;
  gets(s);
  printf("%d",wcount(s));
  return 0;
}