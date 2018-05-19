#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MaxSize 1000
#define Log(a) printf("%s\n", a);
#define LogN(a) printf("%ld\n", a);

int wcount(char *s)
{
        size_t length = strnlen(s,MaxSize),count_el = 0;
	int res = 0, count_num = 0;
	if ((length > 0) && (s[0] == ' ')){
		for (count_el = 0; s[count_el] == ' '; count_el++);
	}
	while (count_el < length){
		if (s[count_el] != ' ') count_num = 1;
		else if (count_num == 1){
				res++;
				count_num = 0;
			}
		count_el++;
	}
	if (s[length-1] != ' ') res++;

	return res; 
}

int main()
{
	char str[MaxSize];
	gets(str);
	printf("%d", wcount(str));
	
	return 0;
}