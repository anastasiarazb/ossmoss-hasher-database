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
	getchar(); getchar(); getchar();
	return 0;
}
int wcount(char *s)
{
	int x, count, l;
	x = 0;
	count = 0;
	l = strlen(s) - 1;
	while (x < l){
		if ((s[x] == ' ')&&(s[x+1] != ' ')) count += 1;
			++x;
	}
	x = 0;
	if ((count == 0)&&(s[0] != ' ')&&(l != -1)) return 1;
	return count;
}