#include <stdio.h>
#include <stdlib.h>

int wcount(char *s)
{
    int nw=1,i;
    for (i=0; s[i]!=EOF; i++)
    {
        if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
            nw++;
    }
    return nw;
}

int main (int argc, char const *argv[])
{
        char mas[1000],*str;
    str=&mas[0];
	gets(mas);
	printf("%d\n", wcount(str) );
	return 0;
}