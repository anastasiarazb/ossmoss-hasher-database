
#include <stdio.h>
#include <string.h>

int wcount( char *s ) {
int n = 0, k = 0, i;

        for ( i = 0; i < strnlen(s,100); i++ ) {
		if ( s[i] == ' ' ) {
			if ( n!=0 )
				k++;
			n=0;
		}
		else {
			n=n+1;
			if ( i == strnlen(s,100)-1 ) 
				k++;
		}
	}
	return k;
}

int main ( int argc, char **argv )
{
	char s[100];
	gets ( s );
	printf ( "%d\n", wcount(s) );
	return 0;
} 