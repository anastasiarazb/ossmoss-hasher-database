#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_len 1024

int wcount(char *s) 
{ 
        int i, ln, num=0;
    
        ln = strnlen(s, max_len);
	
	for (i=0; i<(ln-1); i++)
	{
	        if ( (s[i] == ' ') && (s[i+1] != ' ') )
		num++;
	}
	
	if (s[0] = ' ')
        	num--;
		
	if (s[ln] != ' ')
		num++;
	
	return num;
}

int main(int argc, char **argv)
{
        int num;
	char s[max_len] = {0};
	
	gets(s);
	num = wcount(s);
	
	printf("%d \n", num);
	return 0;
}
