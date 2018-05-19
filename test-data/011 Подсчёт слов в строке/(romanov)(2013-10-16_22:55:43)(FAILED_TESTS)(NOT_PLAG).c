# include <stdio.h>

int wcount(char *s)
{
    int i = 0, ans = 0;
    for(;s[i] != 0;)
    {
        while(s[i] == ' ' && s[i] != 0)
        {
            ++i;
        }
        if(s[i] != 0)
        {
            ++ans;
        }
        while(s[i] != ' ' && s[i] != 0)
        {
            ++i;
        }
    }
    return ans;
}

int main (int argc , char **argv )
{
    char i = 0;
    char *s = i;
    gets(s);
    printf("%d", wcount(s));
    return 0;
}
