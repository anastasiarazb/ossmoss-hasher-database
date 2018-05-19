#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int wcount(char*s, int n){
        int i=0, buf=0,set=0;
        while(i<=n){
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
        n=strlen(s);
	set=wcount(s, n);
	printf("%d\n", set);
        return 0;        
}