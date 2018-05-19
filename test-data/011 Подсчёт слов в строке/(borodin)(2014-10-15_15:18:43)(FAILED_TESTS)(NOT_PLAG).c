#include <stdio.h>
#include <string.h>
int wcount(char *s) 
{ 
        int i=0, j=0;
        while(s[i]!='\0')
        {
                while(s[i]=' ')
                        i++;
                j++;
                while(s[i]!=' ')
                        i++;
                i++;
        }
        return j;
}
int main()
{
        int p;
        char string[100];
        p=wcount(gets(string));
        printf("%d\n", p);
	return 0;
}
