#include<stdio.h>
#include<string.h>

int wcount(char *s)
{
  int word = 0,i=0,length=0;
  length=strnlen(s,150);
  if(length==0)
    return(word);
  for(i=1;i<length;i++) {
    if(s[i-1]!=' ' && s[i]==' ')
      word++;
  }
  if(s[i-1]!=' ')
    word++;
  return(word);
}
 
int main()
{
  char s[150];
  int answer;
  gets(s);
  puts(s);
  answer=wcount(&s[0]);
  printf("There are %d ",answer);
  printf("words.");
   
  return 0;
}
