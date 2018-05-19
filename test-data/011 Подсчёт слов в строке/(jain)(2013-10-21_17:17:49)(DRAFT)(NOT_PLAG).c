#include <stdio.h>
#include <string.h>
//последняя попытка, valgind бесится =_=
 
int wcount(char *as) 
{
        int a,b,i;
        a=strlen(as);
        b=0;
        for(i=0; i<a; i++) 
        {
                if(as[i] != ' ') 
                {
                        ++b;
			while(as[i] != ' ' && i < b) ++i;
		}
	}
	return b;
}
 
int main() 
{
    int n;
    char string[500];
    gets(stroka);
    n = wcount(stroka)
    printf("%d", n);
    return 0;
} 
 

     