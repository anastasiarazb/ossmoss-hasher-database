
#include <stdio.h>
#include <string.h>

int wcount(char *s) 
{ 
        int i, j = 0;
	for (i = 0; s[i] != 0; ) {
		if ((s[i] != ' ') && (s[i] != 0)) {
			while ((s[i] != ' ') && (s[i] != 0)) {i++;}
			j++;
		}
		else {
			while ((s[i] == ' ') && (s[i] != 0)) {i++;}
		}
	}
	return j;
} 

int main()
{
	char str[100];
	gets(str);
	printf("%d\n", wcount(str));
	return 0;
}