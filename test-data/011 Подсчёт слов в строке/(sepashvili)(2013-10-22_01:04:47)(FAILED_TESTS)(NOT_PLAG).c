
#include <stdio.h>

int wcount(char*);

int main()
{
    char string[256];
    int i=0;
    gets(string);

    i = wcount(string);
    printf("\n%d\n", i);

        return 0;
}


int wcount(char* string){
	int i=0;
	int count;

	if(string[i]=='\0'){
		count = 0;
	}else{
		count = 1;
	}

	while(string[i] == ' ')
		i++;

	while(string[i]){
		if(string[i] == ' '){
			count++;
			while(string[i] == ' '){
				i++;
			}
		}
		i++;
	}

	if(string[i-2] == ' '){
		count--;
	}

	return count;
}