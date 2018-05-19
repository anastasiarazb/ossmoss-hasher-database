#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int wcount(char *s)
{
    int k, i = 0 , a = strlen(s);
    for ( k = 0; k <= a - 1; k++ )
        if ( s[k] != ' ' && s[k+1] == ' ' ) i++;
        else if ( s[k] != ' ' && s[k+1] == 0   ) 
        {
            i++;
            break;
        }
    return i;
}
int main()
{
    char *s;
        s =(char*)malloc(1000*sizeof(char));
    memset(s, 0, 1000);
	gets(s);
	int i = wcount(s);
    printf("%d ", i);
	free(s);
    return 0;
}
