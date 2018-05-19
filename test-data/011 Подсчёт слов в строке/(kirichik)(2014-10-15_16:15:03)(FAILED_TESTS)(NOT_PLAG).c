#include <stdio.h>
#include <string.h>
int wcount(char *s)
{        	
	int i=0, nw=0;
 	for (i=0;i<strlen(s)-1;i++){
		if (s[i] == ' ' && s[i+1] != ' ')
		nw++;		
	}
	if(s[0] != ' ')
	nw++;	
	return nw;	
}

int main ()
{ 
        char s[1000];
	gets(s);
        printf("%d\n", wcount(s)); 
        return 0; 
} 