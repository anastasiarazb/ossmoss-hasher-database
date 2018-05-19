#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int wcount(char *s)
{
  int a;
  a = 0;
  int b;
  if (*s == 0) return 0;
  else 
        {
          if (*s != ' ') a++;
            for( b = 0; b < N; b++) 
                 {        
                      if (*(s+b*sizeof(char)) == ' ' &&  *(s+(b+1)*sizeof(char)) != ' ' ) a++ ;
                   if (*(s+b*sizeof(char)) == ' ' &&  *(s+(b+1)*sizeof(char)) == 0 ) a--;
          	 }
	return a;
        }       
}
int main(int argc, char** argv) {
        long r,i,j;
        r = i = j = 0;
        char s[100000];
        gets(s);
        for (i=0;i<strlen(s);i++) {
                if (j == 1) 
                        break;
        else { 
                if (s[i] != ' ') {
                        s[j] = s[i];
                        j=j+1;
	        }       
        }
        }
        if (j == 0) 
                s[j]='\0';
        if (strlen(s) == 0) {
                printf ("0");
                return 0;
        }  
        r = wcount (s);
        printf("%ld", r);
        return 0;
} 