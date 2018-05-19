
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int wcount(char *s);

int main()
{	
	char s[255] = {0};
	gets(s);
	int kol_slov = wcount(s);
	printf("%d", kol_slov);
	return 0;
}

int wcount(char *s) 
{
	int kol = 0;
	int i = 0;
	for(i = 0; i < strlen(s); i++){
		if((s[i] == ' ') && (i != strlen(s) - 1) && (s[i + 1] != ' '))
			kol += 1;
		if(i == 0 && s[i] != ' ')
			kol++;
	}
	return kol;
}
 