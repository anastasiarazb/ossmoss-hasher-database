#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char isLetter(char);
int numwords(char*);

int main()
{
        char *string;
	string = (char*) malloc(1024);
	gets(string);
	printf("%d\n", numwords(string)); 
	free(string);
	return 0;
}

char isLetter(char a)
{
	if ((a >= 'A' && a <= 'Z') ||
	    (a >= 'a' && a <= 'z')) 
            return 1;
	else return 0;
}

int numwords(char *text)
{
	int count = 0, textlen = strlen(text) + 1;
	char *p, isPrevLetter = 0;
	for (p = text; p < text + textlen; ++p)
	{
		if (isLetter(*p)) isPrevLetter = 1;
		else
		{
			if (isPrevLetter) ++count;
			isPrevLetter = 0;
		}
	}
	return count;
}