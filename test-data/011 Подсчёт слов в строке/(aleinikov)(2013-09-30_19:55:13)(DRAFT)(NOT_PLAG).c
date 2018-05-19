#include <stdio.h>
#include <stdlib.h>
#define N 1024
int wcount(char *s) 
{
        char *p, flag=0;
	int am=0;
	for (p=s;*p!='\0';p++){
		if ((*p!=' ')&&(flag==0)){
			flag=1;
			am=am+1;
		}
		if ((*p==' ')&&(flag==1)) flag=0;
	}
	return am;
} 
int main()
{
	char *str=(char*)malloc(N*sizeof(char));
	gets(str);
	printf("%d",wcount(str));
	free(str);
	return 0;
}