#include <stdio.h>
#include <string.h>
 
int wcount(char *as) 
{
        int a , b, i;
        a = strlen(as);
        b = 0;
        for(i = 0; i < a; i++) 
        {
                if(as[i] != ' ') 
                {
                        ++b;
			while(as[i] != ' ' && i < b) ++i;
		}
	}
	return count;
}
 
void main() {
    int size = 512;
    char string[size];
    gets(stroka);
    
    printf("%d", wcount(string));
}
 

     