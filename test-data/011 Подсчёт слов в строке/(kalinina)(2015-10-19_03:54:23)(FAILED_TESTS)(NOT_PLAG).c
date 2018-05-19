
#include <stdio.h>
#include <string.h>

int wcount(char *s) 
{ 
        int i, n, flag;
	n=0;
	flag=0;
	for (i=0; i<strlen(s); i++) {
		if ((s[i] != ' ') && (flag==0)) {
			flag=1;
			n=n+1;
		}
		else if ((s[i] != ' ') && (flag==1)) continue;
                else flag=0;
	}
        return n;
}

int main(int argc, char **argv)
{
	int x;
	char s[x];
	gets(s);
	printf ("%d", wcount(s));
	return 0;
}