#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int wcount(char *s)  {
int i,k=0,j,j1,o=0;

    int n=strlen(s);
  
  if(n!=0) {
   
   for(i=0;i<n;i++)
  if (s[i]==' ') o++;
  
  if (o!=n)
  
  {
  int t=1;

        
         for(i=0;i<n;i++) 
    if (s[i] != ' '&&t==1) {
            j=i;
         t=0;
    }
    t=1;
    
    for(i=n-1;i>=0;i--)
     if (s[i] != ' '&&t==1) {
    	j1=i;
         t=0;
    }
    for(i=j;i<j1;i++)
    if (s[i]!=' '&&s[i+1]==' ') k++;
       
     printf("%d",k+1); }
     
     else printf("0");
     
     }
     
    else printf("0");
  
 
    
        return 0;
} 
int main() {
	char s[200]="";
    gets(s);
    wcount(s);
	 
	return 0;
} 