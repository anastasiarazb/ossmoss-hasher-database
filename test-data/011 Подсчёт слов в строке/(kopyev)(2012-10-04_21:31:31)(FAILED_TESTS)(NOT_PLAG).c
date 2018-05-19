
#include <stdio.h>
#include <string.h>
int wcount(char *s) 
{ 
  int d=0,slova=0,i=0;
  d=strnlen(s,100);
  for (i=1;i<d;i++)  {
    if (s[i]==' ' && s[i-1]!=' ')
      slova++;
  }
  if (s[d-1]!=' ')
    slova++;  
  return (slova);
} 
int main()
{
  char s[100]={0};
  int otvet=0;
  gets(s);
  puts(s);
  otvet=wcount(&s[0]);
  printf("Chislo_slov=%u\n",otvet);
  
  return 0;
}
