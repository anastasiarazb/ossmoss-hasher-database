#include<stdio.h>
#include<string.h>
int wcount(char *s) 
{ 
  unsigned long i;
  int x,k,j;
  k=0;
  char *p;
  x=strnlen( s , 1000000);
  for (p=s,i=0;i<x;i++){
      if (p[i]!=' '){
        k+=1;
	while(p[i]!=' ' && p[i]!=0)
	  i++;
     }
    }
  return k;
}    
int main()
{
  char s[1000000];
  int i;
  char *p=s;
  char *gets(char *p);
  gets(s);
printf("%d",wcount(p));
}

