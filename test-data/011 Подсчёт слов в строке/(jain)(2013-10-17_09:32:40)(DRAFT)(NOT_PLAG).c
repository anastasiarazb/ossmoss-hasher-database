
#include <stdio.h>
void change(char*);
int wcount(char*);
int main()
{
        char s[255];
        int d;
        gets(s);
        d = wcount(s);        
        printf("%d", d);
}   


int wcount(char *s)
{
        int i, q, ;
        state = 1;
        q = 0;
        i = 0;
        while ( s[i] != '\n' ) 
                {
                        if (s[i] != ' ') state = 1;
                        else if (state == 1) 
                                {
                                        state = 0;
                                        ++q;
                                }
                        ++i;
                }
        return q;
}
                   