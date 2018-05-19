#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcout (char *s){

    int i, kol = 0, buf;

    for(i = 0; s[i] != 0; i++){

        while ( s[i] == ' ' && s[i] != 0 ){
            i++;
        }

        buf = i;

        while ( s[i] != ' ' && s[i] != 0 ){
            i++;
        }

        if ( buf != i ){
            kol++;
        }
    }
return kol;
}

int main(){
    int i ;
    char *string = (char*)malloc(100);
    gets(string);
    i = wcout(string);
    free( string );
    printf("\t kolichestvo slov v stroke\t%u\t\n",i);
    return 0;
}
