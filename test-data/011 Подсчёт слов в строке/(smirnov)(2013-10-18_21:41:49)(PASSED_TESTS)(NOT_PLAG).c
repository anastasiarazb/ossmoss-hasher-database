#include <stdio.h>
#include <string.h>

int wcount(char *str);

void main() {
    int size = 512;
    char string[size];
    gets(string);
    printf("%d", wcount(string));
}

int wcount(char *str) {
    int len = strlen(str), count = 0, i;
    for(i = 0; i < len; i++) {
          if(str[i] != ' ') {
        		  ++count;
			  while(str[i] != ' ' && i < len) ++i;
		  }
	}
	return count;
}