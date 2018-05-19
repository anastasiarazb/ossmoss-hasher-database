#include <stdio.h>
#include <string.h>


int wcount(char *s)
{
        char *gets(char *s);
	int i, n, k = 0;
	n = strnlen (s, 100);
	if( s[0] != (' '))
			k++;
	for (i= 1; i < n; i++)
	{
		
		if ((s[i] != ' ') && (s[i-1] == ' '))
				k++;
	}
	
	return k;
}




int main(int argc, char **argv)
{
  int n=0, r;
 // char s[100];
char *s = malloc(100);

gets(s);

  n = wcount(s);
  printf("%d\n", n);
  
  return 0;
}
