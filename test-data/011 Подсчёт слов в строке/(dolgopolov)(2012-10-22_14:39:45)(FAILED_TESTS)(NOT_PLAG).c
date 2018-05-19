/*у меня почему-то этот тест проходит*/
#include <stdio.h>

int wcount (char *str){
        int i, a, count=0;
	a=strlen(str);
	for (i=0; i<=a; i++){
			if (str[i]==32) continue;
		if (str[i]!=32){
                        count++;
		        while (str[i]!='\0')i++;  
	        	while (str[i]!=' ')i++;  
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
