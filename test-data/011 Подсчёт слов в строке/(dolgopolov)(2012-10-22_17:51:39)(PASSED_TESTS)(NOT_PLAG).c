#include <stdio.h>

int wcount (char *str){
        int i, a, count=0, flag=1;
	a=strlen(str);
	for (i=0; i<a; i++){
		if (str[i]==32){
			flag=1;
			continue;
		}
		if (str[i]!=32){
			if (flag){
				count++;
				flag=0;
			}
			continue;
		}
	}
	return count;
}
	
main(){
	char s[100];
	gets (s);
	printf ("%d\n", wcount (s));
 	return 0;
}