#include <stdio.h>

int wcount(char *s) {
    int i, j;
    for ( i=0, j=0; s[i]!=NULL; i++ ) {
        if ( s[i] != ' ' && s[i+1] == ' ') {j++;}
        if ( s[i] != ' ' && s[i+1] == NULL) {j++;}
    }
    return j;
}

int main(int argc, char **argv) {
    char a[1000];
    int i=0;
    gets (a);
    i= wcount(a);
    printf("%d slov", i );
    if ( i%10==1 ) { printf("o"); }
    if ( i%10==2 || i%10== 3 || i%10== 4 ) { printf("a"); }
    return 0;
}
