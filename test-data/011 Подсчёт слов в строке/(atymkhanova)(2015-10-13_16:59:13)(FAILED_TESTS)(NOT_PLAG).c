#include<stdio.h>
main()
{
  int wcount(char *s);
  
  int i;
  char s[100];
  gets(s);
  printf("%d",wcount(s));
}

int wcount(char *s)
{
  int len=strlen(s);
  int i,k=0;
  for (i=0;i<len;i++) {
    if ((s[i]==' ')&&(s[i-1]!=' ')) k++;}
    return (k+1);
  
}