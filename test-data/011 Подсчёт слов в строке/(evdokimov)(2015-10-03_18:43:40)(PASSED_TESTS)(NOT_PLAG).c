#include <stdio.h>

int wcount(char *s)
{
    int i,fur,words;
    i=0;
    fur=1;
    for (words=0; s[i]!=0; i++){
        if ((fur!=0) && (s[i]!=' ')){
            fur=0;
            words++;
        }else if (s[i]==' '){
            fur=1;
        }
    }
    
    return words;
}

int main(int argc, const char * argv[]) {
    const int m = 8*1000;  
    char string[m];
    
    gets(string);
    
    printf("%d \n", wcount(string));
    return 0;
}
