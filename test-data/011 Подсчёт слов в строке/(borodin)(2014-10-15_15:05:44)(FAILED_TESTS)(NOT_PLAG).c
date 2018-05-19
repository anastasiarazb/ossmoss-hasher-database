#include <stdio.h>
#include <string.h>
int wcount(char *s) 
{ 
        scanf("%c ");
        int i=0, j;
        for(j=0;j<strlen(s); j++)
        {
                while(!' ')
                {
                        scanf("%c");
                        j++;
                }
                i++;
                while(' ')
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
        char string[100];
        p=wcount(gets(string));
        printf("%d\n", p);
	return 0;
}
