
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int wcount(char *s)
{
        int i,summ=0;
        if(strlen(s)==0) return 0;
        else{
	  for(i=0;i<(strlen(s));i++){
	    if((s[i]==' ')&&(s[i+1]!=' ')) summ++;
	  }
	  return summ;
	}
}
int main()
{
	char s[100];
	gets(s);
	return 0;
	printf("%d",wcount(s));
}
