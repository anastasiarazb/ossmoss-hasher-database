#include <stdio.h>
#include <string.h>
int wcount(char *s){        	
	int i=0, nw=0;
 	while(s[i] != '\n'){
		if (s[i] == ' ')
		nw++;		
	}
	return nw;	
}

int main ()
{ 
        char s[1000];
	gets(s);
        printf("%d\n", wcount(s)); 
        return 0; 
} 