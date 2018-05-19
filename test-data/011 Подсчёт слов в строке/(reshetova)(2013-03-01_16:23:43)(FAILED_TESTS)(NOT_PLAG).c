#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int wcount(char*s){
        int i, set=0;
	for(i=0; s[i]!='\0'; i++){
		if(s[i]!=' '){
			set++;
			while(s[i]!= ' ' && s[i]!= '\0')
				i++;
		}
	}
	return set;
}

int main(){
	int n, set;
        char s[1024];
        gets(s);
	set=wcount(s);
	printf("%d\n", set);
        return 0;        
}