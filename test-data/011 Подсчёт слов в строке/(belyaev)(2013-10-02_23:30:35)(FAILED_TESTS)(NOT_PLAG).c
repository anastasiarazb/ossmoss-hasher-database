
#include <stdio.h>
#include <string.h>

int wcount (char *s)
{
    int n = 0, i;
    for (i = 0; i < strlen(*s) - 1; ++i )
        if ((s[i]!=" ") && (s[i + 1]==" "))
            n++;
    return n;
}

int main()
{
        char s;
        gets(s);
        printf("%d", wcount(s));
	return 0;
}
