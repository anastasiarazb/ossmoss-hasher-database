#include <stdio.h>
#include <conio.h>
int wcount(char *s);
int main()
{
        char a[255];
	gets(a);
	printf("%d",wcount(a));
	_getch();
	return 0;
}

int wcount(char *s) 
{ 
	if (s[0]=='\0')
        {
		return 0;
	}
	int count=0;
	int i=0;
	while (s[i+1]!='\0')
	{
		if ( s[i]!=' ' && s[i+1]==' ') count++;
		i++;
	}
	return count; 
}