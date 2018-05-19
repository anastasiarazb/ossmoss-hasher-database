
#include <stdio.h>


int wcount(char *s)
        {
                int n;
	        for(n=0;*s;)
                {
		        while(*s==' '&&*s) s++;
		        n+=!!*s;
		        while(*s&&*++s!=' ');
	        }
	return n;
        }	
char *ff (char *s)
        {
	        int i;
	        char *t=new char[255];
	        for(i=0;*s;i++)
                {
		        t[i]=*s;
		        if(*s==' ') while(*++s==' '&&*s);
		        else s++;
	        }
	t[i]=0;
	return t;
        }

int main(){
	char *tmp=new char[255];
	char *tt=new char[255];
	int num;
	gets(tmp);
	tt=ff(tmp);
	num=wcount(tmp);
	cout<<num<<endl;
	cout<<tt<<endl;
	return 0;
}