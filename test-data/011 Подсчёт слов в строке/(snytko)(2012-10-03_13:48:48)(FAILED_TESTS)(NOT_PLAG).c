
#include <stdio.h>

int wcount(char *s)
{
        int i = 1, counter = 0; 
        
        /*
        действительно, не заметил. но, что странно у меня вседа показывала
        правильный результат. и в убунту и в кодблокс.
        */

        while (s[i] != 0)
	{
		if ((s[i] == 0x20 && s[i-1] != 0x20) || (s[i] != 0x20 && s[i+1] == 0)) ++counter;
		++i;
	}
	return counter;
}

int main ()
{
	char str[] = {"00 112  hhhhh hhh ee oooo  hhh   jj"};

	printf("%d\n", wcount(str));
	return 0;
}
