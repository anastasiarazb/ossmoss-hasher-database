#include <stdio.h>
#include <stdlib.h>

int wcount(char *s);

int main()
{
        int i, b, num;
	char *mass;
	mass = (char*)malloc(1000*sizeof(char));
	gets(mass);
        wcount(mass);
        free(mass);
        return 0;
}

int wcount(char *s)
{
	int i, bin_start=1, rez=0;
	for (i=0; i<strnlen(s, 1000); i++)
	{
		if ((int)s[i]==32)
		{
			bin_start=1;
			continue;
		}
		else
		{
			if (bin_start)
			{
				rez++;
				bin_start=0;
			}
		}
	}
	printf("%d", rez);
}