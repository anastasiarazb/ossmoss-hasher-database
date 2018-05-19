#include <stdio.h>
#include <stdlib.h>

int wcount(char *s){
        int i = 0;
	int start = 0;
	int count = 0;

	while (1){
		if (s[i] == '\0' && start == 1){
			count++;
			break;
		}
		if (s[i] == '\0')break;
		if (s[i] != ' ' && start == 0)start = 1;
		if (s[i] == ' ' && start == 1){
			count++;
			start = 0;
		}
		i++;
	}
	return count;
}

int main(){
	char *s = (char*) malloc (100*sizeof(char));
	gets (s);
	printf("%d\n", wcount(s));
}