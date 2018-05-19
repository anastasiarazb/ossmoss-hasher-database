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
	count = 1;
	l = strlen(s);
	while (x < l){
		if ((s[x] == ' ')&&(s[x+1] != ' ')) count += 1;
		else ++x;
	}
        x = 0;
        if(count == 1)
                while(x < l){
                        if(s[x] == ' ') count = 0;
                        else {
                                count = 1;
                                break;
                        }
                        ++x;
                }
	return count;
}