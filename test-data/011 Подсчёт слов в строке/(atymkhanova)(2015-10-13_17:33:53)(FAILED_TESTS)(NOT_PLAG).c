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
   //if ((len==0)&&(s[i]=' ')) k; 
   
  for (i=1;i<len;i++) {
    if ((i==0)&&(s[i]=' ')) k=0;
    if ((s[i]==' ')&&(s[i-1]!=' ')) k++;}
    return (k);
  
}