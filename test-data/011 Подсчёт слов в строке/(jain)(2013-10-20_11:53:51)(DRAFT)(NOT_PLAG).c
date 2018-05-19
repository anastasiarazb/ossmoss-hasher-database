
#include <stdio.h>
int wcount(char*);
int main()
{
        char s[256];
        int d;
        gets(s);
        d = wcount(s);        
        printf("%d", d);
}   


int wcount(char *s)
{
        int i, q, t;
        t = 1;
        q = 0;
        i = 0;
        while (s[i] == ' ')
        { 
                i++;;
        }
        if ((s[i] == '/n') || (s[i] == EOF)) return 0;
        else
        {
          while (( s[i] != '\n' ) || (s[i] != EOF))
             {
                if ((s[i] != ' ') || (s[i] != EOF) || (s[i] != '/n')) t = 1;
                else if (t == 1) 
                        {
                                t = 0;
                                q++;
                        } 
                i++;
             }
        return q;
        }   
}    
     