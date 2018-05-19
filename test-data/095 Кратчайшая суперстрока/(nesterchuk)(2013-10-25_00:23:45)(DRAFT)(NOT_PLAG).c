
#include <stdio.h>
#include <string.h>

void move(char *s, int from, int howmuch)
{
        int i;
        for (i=from; s[i]!=0; i++) s[i] = s[i+howmuch];
}


void cut(char (*s)[n])
{
        int i, j, step, len, flag=0;
        len = strlen(s);
        for (step=len/2; step>0; step--) {
                for (i=0; i<len; i=i+step) {
                        for (j=0; j<step; j++) {
                                if (s[i+j]==s[i+j+step] && s[i+j]!=0) flag=1;
                                else {
                                        flag=0;
                                        break;
                                }
                        }
                        if (flag=1) move(s, i, step);
                        flag=0;
                }
        }
}

void unite(char *sup, char **str, n)
{        
        for (i=0, k=0, j=0; i<256 && k<n; i++, j++) {
                if (j=>strlen(str[k])) {
                        j=0;
                        k++;
                }
                sup[i] = str[k][j];
        }
}

int main()
{
        int n, i, j, k, max=0,
        scanf("%d", &n);
        char str[n][], sup[256]={0};
        for (i=0; i<n; i++) gets(str[i]);


        
	return 0;
}
