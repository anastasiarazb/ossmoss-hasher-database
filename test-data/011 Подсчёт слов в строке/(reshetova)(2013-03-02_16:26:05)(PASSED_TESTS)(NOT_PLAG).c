#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount (char *s){
        
    int i=0, buf, count=0;
    while(s[i]!=0){
            
        while (s[i]==' '&&s[i]!=0){
                i++;
        }
        
        buf = i;
        
        while (s[i]!=' '&&s[i]!=0){
                i++;
        }
        
        if (buf!=i) count++;
    }
return count;
}

int main(){
    char s[1024];
    gets(s);
    printf ("%d\n", wcount(s));
    return 0;
}