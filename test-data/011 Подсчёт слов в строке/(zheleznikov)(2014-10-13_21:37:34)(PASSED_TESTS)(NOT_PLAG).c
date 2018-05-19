#include <stdio.h>

int wcount(char *s)
{
    int q=0;
    if((*s != ' ') && (*s != 0x0A))
    {
        q++;
         s++;
    }
       
    while(*s != 0x0A)
    {
        if ( (*(s-1)==' ') && (*s !=' ') )
            q += 1;
        s++;
    }
        return q;
}
int main(int argc, const char * argv[]) {
    char s[1000];
    fgets(s, sizeof(s), stdin);
    printf("%d", wcount(s));
    return 0;
}
