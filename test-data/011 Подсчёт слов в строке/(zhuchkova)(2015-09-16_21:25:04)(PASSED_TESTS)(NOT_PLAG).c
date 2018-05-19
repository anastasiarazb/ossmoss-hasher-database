#include <stdio.h>
#include <string.h>

int wcount(char *s);

int main()
{
    char str[2000];
        gets(str);	
	printf("%d\n", wcount(str));
	return 0;
}

int wcount(char *s) 
{ 
	int len = strlen(s), i, flag = 0, count = 0;
	
	for (i = 0; i < len; i++) {
		if (s[i] != ' ') {
			if (!flag) count++;
			flag = 1;
		} else flag = 0;
	}
	
	return count;
} 