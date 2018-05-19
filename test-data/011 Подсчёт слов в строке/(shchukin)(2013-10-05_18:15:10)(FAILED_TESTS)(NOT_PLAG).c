#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int wcount(char *s)
{
    int i,summ=0;
    printf("length = %d\n", strlen(s));
    if((strlen(s))==0) return 0;
        else{
        if((strlen(s))!=' ') summ++;
        for(i=0;i<(strlen(s))-1;i++){
	    if((s[i]==' ')&&(s[i+1]!=' ')) summ++;
	  }
	  return summ;
	}
}
int main()
{
	char s[100];
	gets(s);

	printf("%d",wcount(s));
}


