#include <stdio.h>

#define IN 1
#define OUT 0

int wcount(char *s){
    
    int i=0;
    int f=OUT;
    int nspace=0;
    
    while(*s){
        nspace=(*s)!=32;
	i += !f && nspace;
	f = nspace;
	s++;
    }
    return i;        
} 

int main(int argc, char **argv){
    
    char string [100];
    
    gets(string);
    printf("%d\n", wcount((char*)string));
   
    return 0;
}