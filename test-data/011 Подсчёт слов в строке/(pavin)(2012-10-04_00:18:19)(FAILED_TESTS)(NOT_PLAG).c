
#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
        int i, sum = 0, p = strlen(s);
	if (s[0] == ' ') {
		for (i = 0; i < p; i++) {
			if (s[i] == ' ' && s[i + 1] != ' ')
				sum++; 
		}
	}
	else {
		sum = 1;
		for (i = 0; i < p; i++) {
			if (s[i]==' ' && s[i+1]!= ' ')
				sum++;
		}
	}
	return sum;
}

int main()
{
	char str[1000];
	gets(str);
	printf("%d\n", wcount(str));
	return 0;
}