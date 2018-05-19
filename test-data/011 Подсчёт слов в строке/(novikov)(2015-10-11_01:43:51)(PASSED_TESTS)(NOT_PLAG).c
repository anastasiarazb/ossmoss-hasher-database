#include <stdio.h>
#include <string.h>
int wcount(char* s)
{        
	int in = 0;
	int word=0;
	int i=0;
	int len = (strlen(s));
	for(i=0; len>i; i++){
		if (*(s+i) == ' '){
			in= 0;
		}	
		else if (in ==0){
			in=1;
			word++;
		}
	}
	return word;
}	
int main()
{
	char* s=(char*)malloc(1000*sizeof(char));
	gets(s);	
	printf("%d", wcount(s));
	return 0;
}