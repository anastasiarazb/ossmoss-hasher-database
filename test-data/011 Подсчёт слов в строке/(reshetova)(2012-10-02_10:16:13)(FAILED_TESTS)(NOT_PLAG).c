
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *str)
{
        int count = 0, in_word = 0;

        while (*str++)
        	if (*str == ' ' && in_word == 1) {
			
			count++;
			in_word = 0;

		}
		else if (*str != ' ' && *str && !in_word)
			in_word = 1;

	return (in_word) ? count + 1 : count;
}

#define BUFFER_SIZE 1024


int main(void)
{
        char *buffer = (char *) malloc(BUFFER_SIZE);
        
	fgets(buffer, BUFFER_SIZE, stdin);

	printf("%d\n", wcount(buffer));

	free(buffer);

	return 0;
}
