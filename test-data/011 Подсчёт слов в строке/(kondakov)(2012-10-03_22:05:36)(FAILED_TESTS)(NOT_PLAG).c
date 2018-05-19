
#include <stdio.h>
#include <string.h>
#define MAX 100
int wcount(char *s)
{
    int cout = 1, i = 0, j, index = 0;
    while (s[i] == ' ')
    {
        i++;
        index = i;
    }
    for (i = index; i < strlen(s) - 1; i++)
        for (j=1; j< strlen(s); j++)
            if(s[i] == ' ' && s[i+j] != ' ')
            {
                cout++;
                break;
            }
                else break;
    return cout;
}
int main(int argc, const char * argv[])
{
    
    char s[MAX];
    gets(s);
    
    printf("Hello, World!\n%d", wcount(s));
    return 0;
}
