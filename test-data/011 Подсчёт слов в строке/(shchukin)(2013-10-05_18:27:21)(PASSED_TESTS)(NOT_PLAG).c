#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int wcount(char *s)
{
    int i,j,summ=0,unsumm=0;
    
    if((strlen(s))==0) return 0;
    else{
        for(j=0;j<strlen(s);j++) if(s[j]!=' ') unsumm++;
        if(unsumm==0) return 0;
        else{
            if(s[0]!=' ') summ++;
            
            for(i=0;i<(strlen(s))-1;i++){
            if((s[i]==' ')&&(s[i+1]!=' ')) summ++;
            }
        return summ;
        }
    }
}
int main()
{
        char s[100];
	gets(s);

	printf("%d",wcount(s));
}



