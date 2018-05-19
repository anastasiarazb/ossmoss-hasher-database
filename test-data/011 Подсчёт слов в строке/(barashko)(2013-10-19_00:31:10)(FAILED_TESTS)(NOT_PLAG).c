#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int wcount(char *s) 
{ 
        int i, len, total;
        char *j;
	len = strlen(s);
	total = 0;
	for (j = s; *j != '\0'; j++) {
		if (*j == ' ') {
			total++;
		}
		i++;
	}
	total++;
	return total;
}

int main()
{
	char *string;
	int a;
	string = malloc(1000);
	gets(string);	
	a = wcount(string);
	printf("%d\n", a);
	free(string);
	return 0;
}