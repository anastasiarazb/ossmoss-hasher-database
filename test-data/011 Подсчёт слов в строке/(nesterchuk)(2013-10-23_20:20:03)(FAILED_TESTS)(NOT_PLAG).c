
#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
        int n=0, i;
        for (i=0; i<strlen(s); i++) {
                if (s[i]!=" " && (s[i+1]==" " || s[i+1]==EOF)) n++;
        }
        return n;
}


int main()
{
        char s[256]={0};
        gets(s);
        printf("%d", wcount(s));
	return 0;
}
