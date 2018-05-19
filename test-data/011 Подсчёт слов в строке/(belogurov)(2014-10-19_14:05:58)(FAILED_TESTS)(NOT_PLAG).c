
#include <stdio.h>
int wcount(char *s) 
{ 
        int k = 0, test = 0;
	for(int i = 0; s[i] != '\0'; i++)
		if (s[i] != ' ')
			test = 1;
	if (test == 0)
		return k;	
	for(int i = 0; s[i] != '\0';i++)
		if (s[i] == ' ' && s[i+1] != ' ')
			k++;
	return k; 
}

int main(int argc, char **argv)
{
	char str[10000];
	gets(str);
	printf("%d\n", wcount(str));

	return 0;
}