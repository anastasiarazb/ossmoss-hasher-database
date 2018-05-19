
#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    char s;
    gets(s);
    wcount(s);
    return 0;
}

int wcount (char *s)
{
    int i, count=0;
    if ((s[0] != ' ') && (s[0] != '\n')) (count += 1);
    for(i = 1; i < strlen(s)-1; ++i)
    {
        if ((s[i-1]==' ') && (s[i] !=' ')) (count += 1);
    }
    printf("%d\n", count);
    return count;
}