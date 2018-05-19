#include<stdio.h>
#include<string.h>

int wcount(char * s) 
{ 
    int k=0,p=0,b;
    
    while(k<strlen(s))
    {
      while(s[k]==' ')
        k++;
      if(k==strlen(s)) break;
      p++;
      while(s[k]!=' ')
        k++;
    }
    return p;
}

int main()
{
  char s1[2000];
  gets(s1);
  printf("%i\n",wcount(s1));
}
