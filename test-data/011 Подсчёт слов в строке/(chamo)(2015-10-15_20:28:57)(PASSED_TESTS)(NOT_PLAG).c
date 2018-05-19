
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long wcount(char *s)
{
        long i = 0, k = 0;
		while (*(s + i) != '\n') {
			if (*(s + i) == '\0') 
				return k;
			else
				if (*(s + i) == ' ') 
					i = i + 1;
				else {
					while (*(s + i) != ' ') {
						if ((*(s + i) == '\0') || (*(s + i) == '\n')) 
							return k + 1;
						i = i + 1;}
					k = k + 1;}}
	return k;
}



int main(int argc, int **argv)
{	
	char *s;
	s = malloc(300);
	gets(s);
	printf("%ld\n", wcount(s));
	free(s);
	return 0;
}
