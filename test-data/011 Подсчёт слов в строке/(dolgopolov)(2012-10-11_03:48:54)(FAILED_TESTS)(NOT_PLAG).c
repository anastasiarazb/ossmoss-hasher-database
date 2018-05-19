#include <stdio.h>

int wcount (char *str){
int i, count=0;
        i = strnlen (str, sizeof(char*));
	for (i; i>0; i--){
		while ( str[i] != 32 ){
			i--;
			break;
		}
                if (i==0)
                        return 0;
		while ( str[i] == 32 )
			i--;
		count++;
	}
	return count;
}

main(){
	char s[100];
	gets (s);
	printf ("%d\n", wcount (s));
	return 0;
}
