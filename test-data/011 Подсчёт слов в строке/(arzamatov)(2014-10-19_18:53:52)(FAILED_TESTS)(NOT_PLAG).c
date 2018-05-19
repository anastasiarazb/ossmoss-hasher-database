int wcount(char *s) 
{ 
        int i=0,c=0;
	if((*(s))==0){return 0;}
	while(*(s+i+1)!=0){
		if((*(s+i))!=' '){
			if((*(s+i+1))==' ' || (*(s+i+1))==0){
				c++;
			}
		}
		if((*(s+i+1))==0){break;}
                i++;
	}

	return c;
} 
#include <stdio.h>
#include <string.h>
int main()
{
	char s[100000];
	gets (s);
	printf("%d\n",wcount(s));
	return 0;
}