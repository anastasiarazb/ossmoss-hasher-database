#include <stdio.h>
#include <string.h>
 
int wcount(char *s)
{
        int i, k = 0;
	for (i = 0; i < (strlen(s) - 1); i++)
		if ((s[i] != ' ') && (s[i + 1] == ' ')) k++;
	if (s[strlen(s) - 1] != ' ') k++;
        
	return k;
}
 
int main()
{
	char s[100];
	gets(s);
        
        if (strlen(s) != 0) printf("%d", wcount(s));
        else printf ("0");
        
	return 0;
}