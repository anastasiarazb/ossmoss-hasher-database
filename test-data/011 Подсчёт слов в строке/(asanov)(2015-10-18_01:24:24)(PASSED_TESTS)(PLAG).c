#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s);

int main(void)
{
              char *str = malloc(sizeof(char)*1000);
	gets(str);
	printf("%d \n", wcount(str));
	free(str);
	return 0;
}

int wcount(char *s) 
{ 
	int count = 0;
	int x = 0;
	const int N = strlen(s); 
	int i = 0;
	for(i = 0; i < N; i++)
	{
		if(s[i] == ' ')
		{	
			x = 0;
		}
		else
		{
			x = 1;
			while(x == 1 && i < N)
			{
				i++;
				if(s[i] == ' ')
				{
					x = 0;
				}
			}
			count++;		
		}
	}
	return count;
       
}