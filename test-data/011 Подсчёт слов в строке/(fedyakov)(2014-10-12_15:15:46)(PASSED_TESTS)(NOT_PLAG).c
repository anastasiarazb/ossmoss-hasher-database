#include <stdio.h>
#include <string.h>

#define IN 1
#define OUT 0

int wcount(char *s) 
{   unsigned long len, i = 0, wcounter = 0;
    char c = 0, state = OUT;
    //len = strnlen (s, 1000);
    while (c = s[i]) {
        if (c == ' ') state = OUT;
	else if (state == OUT) {
	    ++wcounter;
	    state = IN;
	}
	i++;
    }
  return wcounter ;
} 


int main()
{	
    char s[10000];
    gets (s); 
    printf("%lu \n", wcount(s));
	return 0;
}
 
