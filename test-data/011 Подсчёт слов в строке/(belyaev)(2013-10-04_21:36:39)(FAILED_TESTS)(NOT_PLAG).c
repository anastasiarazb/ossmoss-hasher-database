
#include <stdio.h>
#include <string.h>

int wcount (char *s)
{
    int n = 0, i;
    n = 0;
    for (i = 0; i < strlen(s) - 1; ++i )
        if ((s+(sizeof(s))*i!=" ") && (s+(sizeof(s))*(i + 1)==" "))
            n++;
    return n;
}

int main(int argc, char **argv)
{
        int m = 0;
        char s[100];
        gets(s);
        m = wcount(s);
        printf("%d", m);
	return 0;
}
