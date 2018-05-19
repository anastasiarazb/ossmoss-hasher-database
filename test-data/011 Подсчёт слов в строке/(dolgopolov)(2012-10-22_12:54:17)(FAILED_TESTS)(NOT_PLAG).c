/*у меня почему-то этот тест проходит*/
#include <stdio.h>

int wcount (char *str){
int i, count=0;
    i = strnlen (str, sizeof(char*))-1;
        if (i==0 && str[0]!=32) return 1;
	for (i; i>0; i--){
		if (i==0 && str[0]!=32) return 1;
		else return 0;
		while ( str[i] != 32 ){
			i--;
			break;
		}
		if (i==0) return 0;
		while ( str[i] == 32 ) i--;
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
