#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int wcount(char *s)
{
        int i, count = 0;
	for (i = 1;s[i] != 0; i++) {
		if ((*(s + i) == ' ') && (*(s + i - 1) != ' ')) count += 1;
	}
	if (*(s+ i - 1) != ' ') count += 1;
	return count;
}

int main()
{
	char *s = (char*)calloc(1000 , sizeof(char));
	gets(s);
	int words = wcount(s);
	free(s);
	printf("%d", words);
	return 0;
}