#include "stdio.h"
#include "string.h"

int wcount(char *s)
{
        int i, wordsCount = 0;
	char inWord = 0;
	for (i = 0; i < strlen(s); ++i)	{
		if (s[i] == ' ') inWord = 0;
		else if(!inWord) {
			wordsCount++;
			inWord = 1;
		}
	}
	return wordsCount;
}

int main(int argc, char const *argv[])
{
	char string[1000];
	gets(string);
	printf("%d\n", wcount(string));
	return 0;
}