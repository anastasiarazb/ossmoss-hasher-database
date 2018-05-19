#include <stdio.h>

int wcount(char *s)
{
        int i, flag=0, res=0;
	for(i=0;i<strlen(s);i++){
		if ((s[i]!=' ')&&(flag==0)) {
			res++;
			flag++;
		}
		else if (s[i]==' ') flag=0;
	}
	printf("%i\n",res);
	
}

int main()
{
	char a[1488];
	gets(a);
	wcount(a);
	return 0;
}