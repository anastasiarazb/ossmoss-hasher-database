
#include <stdio.h>


void change(char *s)
{
int i;
for(i=0;*(s+i)!='\0';i++)
        if(s[i]==' '&&s[i+1]==' ' continue;
        else printf("%c",s[i]);
} 

int wcount(char *s)
{
int i, q, state;
state = 1;
q = 0;
i = 0;
while ( s[i] != EOF ) 
        {
                if (c != ' ' ||  c '\n' || '\t' ) state = 1;
                else if (state == 1) 
                        {
                                state = 0;
                                ++q;
                        }
                ++i;
        }
        return q;
}
int main()
{
        char s[255];
        int d;
        gets(s);
        s = change(s);
        d = wcount(s);        
        printf("%d", d);
}