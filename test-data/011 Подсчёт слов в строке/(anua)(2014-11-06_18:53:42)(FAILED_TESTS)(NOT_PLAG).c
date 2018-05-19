#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int wcount(char *s)
{
    int flag = 0, i, k = 0;
    for( i = 0; i != ' '; i++)
        {
		if (s[i] == ' ')
		{
			flag = 0;
			continue;
		}
		if (flag == 0)
		{
			k++;
			flag = 1;
		}
        if( *s == 0)
            k = 0;
    }
    return k;
}

int main()
{
	char *s;
	s =(char*)malloc(1000*sizeof(char));
    memset(s, 0, 1000);
	gets(s);
	int k = wcount(s);
    printf("%d", k);
	free(s);
    return 0;
}
