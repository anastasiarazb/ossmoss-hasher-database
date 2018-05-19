#include <stdio.h>
#include <stdlib.h>

int wcount(char *s){
    int wcnt = ((*s != ' ') && (*s != '\0'))? 1 : 0;
    while ( *s )
        if ((*s++==' ') && (*s!=' ') && (*s!='\0'))
            wcnt++;
    return wcnt;
}

int main()
{
    char *s = malloc(255 * sizeof(char));
        gets(s);
	printf("%d\n", wcount(s));
	free(s);
    return 0;
}
