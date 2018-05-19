#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define space 32

int wcount(char *s);

void main(){
        char str[256];
	gets (str);
	printf("%d\n", wcount (str));
}
int wcount(char *s){
	int flag = 0, n = 0, i;
	for (i = 0; i < strnlen (s, 256); i++){
		if (s[i] == space){
			if (flag == 1)
				flag = 0;
		}
		else{
			if (flag == 0)
				n++;
			flag = 1;
		}
	}
	return n;
}