
#include <stdio.h>
#include <string.h>

void move(char *s, int from, int howmuch)
{
        int i;
        for (i=from; s[i]!=0; i++) s[i] = s[i+howmuch];
}


void unite(char *s)
{
        int i, j, step, len, flag=0
        len = strlen(s);
        for (step=len/2; step>0; step--) {
                for (i=0; i<len; i=i+step) {
                        for (j=0; j<step; j++) {
                                if (s[i+j]==s[i+step+j] && s[i+j]!=0) flag=1;
                                else {
                                        flag=0;
                                        break;
                                }
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
