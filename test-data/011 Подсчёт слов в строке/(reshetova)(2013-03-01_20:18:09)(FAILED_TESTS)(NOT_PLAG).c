#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int wcount(char*s){
        int i=0, buf=0,set=0;
        while(s[i]!='\0'){
		if(s[i]!= ' '){
			buf=1;
		if(s[i]== ' ' && buf==1){
                        set++;
                        buf=0;
		}
			i++;
		}
                if(buf==1&&s[i]=='\0')
                set++;
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