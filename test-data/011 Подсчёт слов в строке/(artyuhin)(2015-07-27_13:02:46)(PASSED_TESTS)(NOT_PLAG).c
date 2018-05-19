#include <stdio.h>
int wcount(char *s) 
{ 
        int i = 0, count = 0;
	while(1){
		if(s[i] == ' '){
			while(s[i] == ' ') i++;
			if(s[i]== '\0')	break;			
		}
		if(s[i] == '\0')	break;
		while(s[i] != ' '){
			if(s[i] == '\0')	break;
			i++;
		}
		count++;					
	}
	return count;
}
int main()
{
	int n;	
	char str[1000000];
	gets(str);
	printf("%d", wcount(str));
	return 0;
}
