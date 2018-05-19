
#include <stdio.h>
#include <string.h>

int wcount(char *s) 
{
        int dlina=0,i=0, count=0;
	dlina = strnlen(s,50);	
	while(i<dlina){
		if(*(s+i)!=' '){
			count++;
			if (i>0) for(i=i-1;*(s+i)!=' ';i++);
		}
		i++;
	}
	return count;
}


int main(int argc, char **argv)
{       
    char s[50]={ 0 };
	gets(s);
	printf("%d\n", wcount(s));
	return 0;
	
}
