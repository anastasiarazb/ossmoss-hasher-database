
#include <stdio.h>

int wcount(char *s)
{
        int n;
        for (n=0; *gets(s)!=0; n++);
        return n;
}


int main()
{
        char a[256];
        printf("%d\n", wcount(a));
	return 0;
}
