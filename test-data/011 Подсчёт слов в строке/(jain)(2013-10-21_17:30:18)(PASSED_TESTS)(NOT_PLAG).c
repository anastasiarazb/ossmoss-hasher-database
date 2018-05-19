#include <stdio.h>
#include <string.h>
//последняя попытка, valgind бесится =_=
 
int wcount(char *s) 
{
        int a,b,i;
        a=strlen(s);
        b=0;
        for(i=0; i<a; i++) 
        {
                if(s[i] != ' ') 
                {
                        ++b;
			while((s[i] != ' ') && (i<a)) ++i;
		}
	}
	return b;
}
 
int main() 
{
    int n;
    char stroka[500];
    gets(stroka);
    n = wcount(stroka);
    printf("%d", n);
    return 0;
}    
     

     