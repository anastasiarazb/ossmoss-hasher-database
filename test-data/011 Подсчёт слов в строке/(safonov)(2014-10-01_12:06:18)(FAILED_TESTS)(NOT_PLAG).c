#include <stdio.h>
#include <stdlib.h>
#include <string.h>

        char str[1000];
	
int wcount(char * str) {
	int count = 0, n = 0, last_symbol = 0;
	
	while (str[n] != 0) {	
	if (last_symbol == 0) {
		if (str[n] == ' ') {
			last_symbol = 0;
		} else {
			last_symbol = 1;
		}
	} else {
		if (str[n] == ' ') {
			last_symbol = 0;
			count++;
		} else {
			last_symbol = 1;
		}
	}
	n++;
	}
	if (str[n - 1] != ' ') {
		count++;
	}
	return count;
}

int main() {
	gets(str);
	printf("%d",wcount(str));
	return 0;
}
