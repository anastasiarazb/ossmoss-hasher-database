#include <stdio.h>
#include <string.h>




int wcount(char *s) 
{
        int slovo_finder=0,dlina=0,i=0, count=0;
        dlina = strnlen(s,100);
	for(i=0;i<dlina;i++){
		if(s[i]!=' ' && slovo_finder == 0){
			count++;
			slovo_finder = 1;
		}else if(s[i]==' ') slovo_finder =0;
	}
	return count;
}

int main()
{        
	char s[100]={ 0 };
	gets(s);
	printf("%d\n", wcount(s));
	return 0 ;
}