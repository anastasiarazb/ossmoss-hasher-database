#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int wcount(char *s)  {
int i,k=0;

    int n=strlen(s);
        
	 for(i=0;i<n;i++)
       if (s[i]==' ') k++;
       printf("%d",k+1);
       
        return 0;
} 
int main() {
	char s[256];
    gets(s);
	wcount(s);
	return 0;
}