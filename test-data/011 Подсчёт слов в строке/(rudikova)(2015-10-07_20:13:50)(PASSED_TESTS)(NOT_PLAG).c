#include <stdio.h>

int wcount(char *s)
{
    int i =0, count = 0;
    
    while (s[i]){
        while (s[i] == ' ') ++i;
        
        while ((s[i]) && (s[i] != ' ')){
	     if ((s[i + 1] == '\0')||(s[i + 1] == ' ')) ++count;
	     ++i;
	}
    }
    return count;    
}

int main()
{
    char s[100];
    gets(s);
    printf("%d ", wcount(s)); 
    return 0;
}