//16. Подсчёт слов в строке

#include <stdio.h>

int wcount(char *s) { 
        int i, c=0;
	for (i=0; s[i]!=0; i++)
		if (s[i]!=' ' && (i==0 || s[i-1]==' '))
			c++;
	return c;
}

int main() {
	char s[100];
	gets(s);
	printf("%d\n", wcount(s));
	return 0;
}
