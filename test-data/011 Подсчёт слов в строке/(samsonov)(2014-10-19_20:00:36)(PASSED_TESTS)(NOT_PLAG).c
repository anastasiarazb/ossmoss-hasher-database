#include <stdio.h>
#include <stdlib.h>

#define limit 10000

int wcount(char *s)
{
    int number_of_words = 0;
    
        while(*s)
	{
		if((*s != ' ') && (*s != '\n') && (*s != '\t'))
		{
			while((*s != ' ') && (*s != '\n') && (*s != '\t'))
			{
				s++;
			}
			number_of_words++;
		}
		s++;
	}
	return number_of_words;
}

int main (int argc, char **argv)
{
	char words[limit];
	int i = 0;
	while(i < limit)
	{
		*(words + limit) = '\0';
		i++;
	}
	fgets(words, limit, stdin);
	
	printf("%d", wcount(words));
	
	return 0;
}
