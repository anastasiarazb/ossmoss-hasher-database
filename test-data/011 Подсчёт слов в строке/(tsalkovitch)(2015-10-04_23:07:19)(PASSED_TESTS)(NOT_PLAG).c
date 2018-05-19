
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[1000000];

int wcount(char *s)
{
long long key = 1, sum =0;
for (unsigned int i = 0; i < strlen(s); i++)
    if (s[i] == ' ')
        key = 1;
	else if (key && s[i] != ' ')
	{
		sum++;
		key = 0;
	}
return sum;
}


int main()
{
	long n;    
    gets(str);        
    n = wcount(str);
    printf("%ld", n);
}
