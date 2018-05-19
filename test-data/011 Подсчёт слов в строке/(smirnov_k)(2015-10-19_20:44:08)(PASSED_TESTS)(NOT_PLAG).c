#include <stdio.h>
#include <stdlib.h>

int wcount(char*);

int main()
{
        char* s = (char*)calloc(1000, 1);
	gets(s);
	printf("%d", wcount(s));
	free(s);
	return 0;
}

int wcount(char *s)
{
	int i, k, Pr;
	for (i = 0 ; s[i] == ' ' && s[i] != '\0'; i++);
		for (Pr = 0, k = 0; s[i] != '\0'; i++)
			if (s[i] != ' ' && Pr == 0) {
				Pr = 1; 
				k++;
				} 
			else if (s[i] == ' ') Pr = 0; 
	return k; 
}
