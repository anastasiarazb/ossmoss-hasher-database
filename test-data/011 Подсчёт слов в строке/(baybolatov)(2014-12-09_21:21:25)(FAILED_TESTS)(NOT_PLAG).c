#include <stdio.h>
#include <stdlib.h>

int wcount(char *s){
    //>
    int wcnt = 0, space = 0;
    char *s1 = s;
    while ( *s1 ) {
        if ( *s1++ != ' '){
           s1 = NULL;
           break;
        }
    }
    if ( s1 )
        return 0;

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
