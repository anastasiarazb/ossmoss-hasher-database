#include <stdio.h>

int main (int argc, char const *argv[])
{
        char mas[200],*str;
        str=&mas[0];
        gets(mas);
	printf("%d\n", wcount(str) );
	return 0;
}

int wcount(char *s)
{
	int i=0;
	int count=0;
    
	while(s[i]!='\0'){
		if(s[i]!=' '){
			count++;
			while(s[i]!=' ' && s[i]!='\0'){
				i++;
			}
		}
		i++;
	}
    
	return count;
}