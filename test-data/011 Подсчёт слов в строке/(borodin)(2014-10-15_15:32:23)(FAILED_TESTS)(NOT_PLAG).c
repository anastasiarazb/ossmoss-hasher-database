#include <stdio.h>
#include <string.h>
int wcount(char *s) 
{ 
        int i, j=0;
        for(i=0; s[i]!='\0';) 
        {
                while(s[i]==' ')
                        i++;
                if(s[i]!=' '&&s[i]!='\0')
                        j++;
		while(s[i]!= ' ' && s[i] !='\0')
                {
			i++;
                        
	}
        return j;
}
int main()
{
        int p;
        char string[100];
        p=wcount(gets(string));
        printf("%d\n", p);
	return 0;
}
