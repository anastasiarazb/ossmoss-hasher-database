#include <stdio.h>
#include <string.h>
int wcount(char *s)
{
    int q=0;
    if (*s == 0x0A)
    {
        return 0;
    }
    else
    {
        while(*s != 0x0A)
        {
    
            if ((*s == 0x20) && (*(s+1) != 0x20) && (*(s+1) != 0x0A))
            {
                q++;
            }
            s++;
        }
    }
    return ++q;
}
int main(int argc, const char * argv[]) {
    char s[1000];
    fgets(s, sizeof(s), stdin);
    printf("%d", wcount(s));
    return 0;
}
