#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[])
{
    int count1;
    char s[250];
    fgets(s, 250, stdin);
    wcount(s);
    count1 = wcount(s);
    printf("%d", count1);
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
    return count;
}