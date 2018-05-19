#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int wcount(char *s)  {
int i,k=0;

    int n=strlen(s);
        
	 for(i=0;i<n;i++)
       if (s[i]==' ') k++;
      if (k!=0) printf("%d",k+1);
       else printf("0");
        return 0;
} 
int main() {
	char s[256];
    gets(s);
	wcount(s);
	return 0;
} 