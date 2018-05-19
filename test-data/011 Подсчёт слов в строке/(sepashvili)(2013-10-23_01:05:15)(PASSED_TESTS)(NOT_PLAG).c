
#include <stdio.h>

int wcount(char*);

int main()
{
    char string[256]={0};
    int i=0;
    gets(string);
    
    
    i = wcount(string);
    printf("%d", i);

        return 0;
}


int wcount(char* string){
	int i=0;
	int count=0;

	while(string[i]!='\0'){
		if(string[i]!=' '){
			count++;
			while(string[i]!=' ' && string[i]!='\0'){
				i++;
			}
		}
		i++;
	}

	return count;
}