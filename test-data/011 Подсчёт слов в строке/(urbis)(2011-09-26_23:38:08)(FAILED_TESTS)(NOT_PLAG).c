#include <stdio.h>
int natural=0;
int wcount(char *s)
{
        int i, mesto=0, slov=0;
	for (i=0; i<strlen(s); i++)
	{
		if (s[i]==' ')
		mesto=0;
		else
		if (mesto==0)
		{
			mesto=1;
			slov++;
		} 
	}

	return slov;
}
int main()
{
	int slov=0;
	int mesto=0;
	int max=1000;
	int i;
	char c, s[max];
	for (i=0; i<max && (c=getchar())!='\0' && c!='\n'; i++)
	s[i]=c;
	s[i]='\0';
	for (i=0; s[i]!='\0'; i++)
	{
		++natural;
	}
	slov=wcount(s);
	
	printf("%d\n", slov);
}