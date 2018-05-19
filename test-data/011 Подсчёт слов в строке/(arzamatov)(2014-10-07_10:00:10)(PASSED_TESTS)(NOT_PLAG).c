int wcount(char *s) 
{ 
        int i,c=0;
	if((*(s))==0){return 0;}
	for(i=0;i<4999;i++){
		if((*(s+i))!=' '){
			if((*(s+i+1))==' ' || (*(s+i+1))==0){
				c++;
			}
		}
		if((*(s+i+1))==0){break;}
	}

	return c;
} 
#include <stdio.h>
#include <string.h>
int main()
{
	char s[5000];
	gets (s);
	printf("%d\n",wcount(s));
	return 0;
}