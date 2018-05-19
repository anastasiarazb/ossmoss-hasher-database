#include <stdio.h>

int wcount(char *s)
{        
	int i=0,k=0;
	char c;
	while (i < strnlen(s))
	{
		while ((char*)s[i]==' ')
			i++;
				
		while ((char*)s[i]!=' ')
			i++;
		k++;
	}
	printf("%ld",k);
	return k;
}

	
int main()
{
	char str[1000]="";
	int i=0,k=0;
	gest(str);
	wcount(str);

	return 0;
}
