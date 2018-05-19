#include <stdio.h>


int wcount(char *s)
{
    int k,n,i;
    k = n = i = 0;
    while (s[i] != '\0')
    {
        if(s[i] ==' ')
            k = 0;
        else if(k == 0)
        {
            ++ n;
            k = 1;
        }
        ++ i;
    }
    return n;
}


int main(int argc, const char * argv[])
{
    int x;
    char s[250];
    (fgets(s, 250, stdin));
    x = wcount(s);
    printf("%d", x);
}
