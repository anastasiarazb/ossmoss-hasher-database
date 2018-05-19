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
	 int count=0;
	 int i=0;
	 while (s[i]!='\0')
	 {
		 if(s[i]==' ')
			 count++;
		 i++;
	 }
	 return count+1;
}