#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *str){
        int count = 0, in_word = 0;
        while (*str++){
        	if (*str == ' ' && in_word == 1){		
			count++;
			in_word = 0;
		}else{        	        
		 if (*str != ' ' && *str && !in_word)
			in_word = 1;
		}
        }
	return (in_word) ? count + 1 : count;
}

int main(){
        char buffer[1024];
	gets(buffer);
	printf("%d\n", wcount(buffer));
	return 0;
}