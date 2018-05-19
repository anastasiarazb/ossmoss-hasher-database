#include <stdio.h>
#include <string.h>
int wcount(char *s) 
{ 
        scanf("%c ");
        int i=0;
        for(j=0;j<length(s); j++)
        {
                while(!'')
                {
                        scanf("%c");
                        j++;
                }
                i++;
                while('')
                {
                        scanf("%c ");
                        j++;
                }
                        
        }
        return i;
}
int main()
{
        int p;
        char* string;
        p=wcount(gets(string));
        printf("%d\n", p);
	return 0;
}
