#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s)
{
    int word_counter = 0;
   // int length = strlen(s);
    for (int i = 0; s[i] != '\0'; i++) {
        if ((s[i] == ' ') && (s[i+1] != ' ')) {
            word_counter++;
        }
        if((s[i] == ' ') && (s[i+1] == ' ')){
            
        }
        if ((s[i] != ' ') && (s[i+1] != ' ')){
            
        }
    }
    
    return word_counter;
    
}

int main(){
    
    char* s = " Hello   my friend   !  ";
    
    gets(s);
    
    int p = wcount(s);
    
    printf("%d", p);
}