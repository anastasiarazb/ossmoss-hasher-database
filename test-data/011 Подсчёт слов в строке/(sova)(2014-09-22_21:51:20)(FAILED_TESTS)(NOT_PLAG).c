
#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    char s[100];
    gets(s);
    wcount(s);
 return 0;
}

int wcount (char *s)
{
    int i, count;
    if (s[0] != ' ') (count += 1);
    for(i = 0; i <= strlen(s); ++i)
    {
        if ((s[i]==' ') && (s[i-1] !=' '))
            count += 1;
    }
    printf("%ld\n", count);
    return count;

}