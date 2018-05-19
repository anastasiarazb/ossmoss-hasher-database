#include<stdio.h>
#include<string.h>

int wcount(char * s) 
{ 
    int n=strlen(s);
    if (n==1) 
      return 1;
    int k=0,p=0;
    short b;
    
    while(k<n)
    {
      b=0;
      while((k<n) && (s[k]==' '))
        k++;
      while((k<n) && (s[k]!=' '))
      {
        k++;
        b=1;
      }
      if(b) p++;
    }
    
    return p;
}

int main()
{
  char s1[2000];
  gets(s1);
  printf("%i\n",wcount(s1));
}
