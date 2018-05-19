
#include <stdio.h>

int wcount(char *s)
{
        int n=0, i;
        for (i=1; i<strlen(s); i++) {
                if (s[i]=" " && s[i-1]!=" ") n++;
        }
        return n;
}


int main()
{
        int s[256]={0};
        gets(s);
        printf("%d", wcount(s));
	return 0;
}
