
#include <stdio.h>
#include <string.h>

void move(char *s, int from, int howmuch)
{
        int i;
        for (i=from; s[i]!=0; i++) s[i] = s[i+howmuch];
}


void unite(char *s)
{
        int i, j, step, len,
        len = strlen(s);
        for (step=len/2; step>0; step--) {
                for (i=0; i<len; i=i+step) {
                        if (s[i]==s[i+step] && s[i]!=0) {
                                
                        }
                }
        }
}

int main()
{
        int n, i
        scanf("%d", &n)
        char str[n][];
        for (i=0; i<n; i++) gets(str[i]);
	return 0;
}
