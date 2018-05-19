#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int wcount(char *s)  {
int i,k=0;

    int n=strlen(s);
  
   
        
         for(i=0;i<n;i++) 
       if ((s[i] != ' ') && (s[i + 1] ==' ')) k++;

       
 if(n!=0)     printf("%d",k);
    else printf("0");
  
 
    
        return 0;
} 
int main() {
        char s[200]="";
    gets(s);
    wcount(s);
	 
	return 0;
} 