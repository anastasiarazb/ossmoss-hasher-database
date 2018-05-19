#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int wcount(char *s)
{
        int i, words = 0, nel = strlen(s); /* words - количество слов, nel - количество символов */
	if (s[0] == 0) /* Случай пустой строки */
		words=0;
	else
	{
	    if (s[nel-1] != ' ')    /* Проверяем, есть ли слова после последнего пробела */
		    words = 1;
	    for (i = 1; s[i] != '\0'; i++) {    /* Считаем слова до последнего пробела */
		    if (s[i] == ' ' && s[i-1]!=' ')
		        words++;
	}
	}
	free(s);
	return words;
}
int main(int argc, char **argv)
{
	char *s = (int*) malloc(10*sizeof(int));
	gets(s);
	printf("%d", wcount(s));
	return 0;
}