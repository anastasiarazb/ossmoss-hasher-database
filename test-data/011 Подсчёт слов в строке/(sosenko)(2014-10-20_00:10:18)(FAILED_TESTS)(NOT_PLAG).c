
#include <stdio.h>

int wcount(char *s) 
{ 
        int word_number = 0;
        char * cs = s;
        do 
        {
                if ((*cs == ' ' || *cs == '\0') && cs != s && *(cs - 1) != ' ')
                        word_number ++;
                
                cs ++;
        }
        while (*cs != '\0')
        
        printf("%d", word_number);
        return 0;
}

int main()
{
        char s [10000];
        gets(s);
        return wcount(s);
}