#include <stdio.h>

int wcount(char *s)
{
        int per = -1, vtr, k = 0, i;
        for(i=0; (s[i]!='\0' && s[i]!='\n'); i++)
	{
		if(s[i]==' ')
		{
			vtr = i;
			if (vtr-per>1)
			{
				k++;
			}
			per = vtr;
		}
	}
	if(i-per>1)
	{
		k++;
	}
        if((per == -1) && (s[0]!='\0') && (s[0]!='\n'))
	{
		k = 1;
	}
	return k;
}

int main()
{
	char s[1024];
	fgets(s,1024,stdin);
	printf("%i\n", wcount(s));
	return 0;
}