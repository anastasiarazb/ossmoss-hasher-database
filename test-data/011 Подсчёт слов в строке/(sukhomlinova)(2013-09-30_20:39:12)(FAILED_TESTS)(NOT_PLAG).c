
#include <stdio.h>

int wcount(char *s) 
{ 
        char *p, ch;
        unsigned long i = 1, n = 0;
        if ((s[0] != 0) && (s[0] != ' ') n = 1;
        while (s[i]) {
                if ((s[i] == ' ') && (s[i + 1] != ' ')) n ++;
                i++;
        }
        return n;
}

char s[1000];

int main()
{
        gets(&s);
        printf ("%d", wcount (&s));
	return 0;
}
