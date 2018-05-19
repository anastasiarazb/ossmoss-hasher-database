#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
char c[1000];
int wcount(char * c) {
        int i=0,k=0;
	while (c[i] != 0) {
		if ((c[i] != ' ') && ((c[i+1]==0) || (c[i+1] == ' ')))
			k++;
	i++;
	}
return k;
}

int main() {
	gets(c);
	printf("%d", wcount(c));
	return 0;
}