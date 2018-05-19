#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int wcount(char *s);
int main()
{
        int i;
	char temp, str[256];//Метод тыка,для длины..
	gets(str);
	i = wcount(str);
	printf("%d", i);
	return 0;
}
int wcount(char *s)
{
	int x, count, l;
	x = 0;
	count = 0;
	l = strlen(s);
	while (x < l){
		if ((s[x] == ' ')&&(s[+1] != ' ')) if (count == 0) count = 2;
		else count += 1;
		else ++x;
	}
	return count;
}