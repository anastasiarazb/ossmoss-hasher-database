#include <stdio.h>
#include <stdlib.h>

int wcount(char *s){
    //>
    int wcnt = 0, space = 0;
    while ( *s ){
        if (( *s++ ) == ' '){
            if (!space) wcnt++;
            space = 1;
        } else space = 0;
    }
    return wcnt + 1;
}

int main()
{
    char *s = malloc(255 * sizeof(char));
        gets(s);
	printf("%d\n", wcount(s));
	free(s);
    return 0;
}
