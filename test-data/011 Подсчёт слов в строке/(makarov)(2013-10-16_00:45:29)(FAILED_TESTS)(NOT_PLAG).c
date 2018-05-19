#include<stdio.h>
int wcount(char *s) 
{ 
  unsigned long i;
  int k,j;
  k=0;
  for (i=0;i>-1;i++){
    if (s[i]==0){
      break;
    }else{
      if (s[i]!=' '){
      k+=1;
      while(s[i]!=' '){
        i++;
      }
    }
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

