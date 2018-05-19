#include <stdio.h>
#include <string.h>


int wcount(char *s)
{
        char *gets(char *s);
	int i, j, n, k = 0;
	n = strnlen (s, 100);
	for (i= 0; i < n; i++)
	{
		if( s[0] != (' '))
			k++;
		else if ((s[i] != ' ') && (s[i-1] == ' '))
				k++;
	}
	
	return k;
}




int main(int argc, char **argv)
{
  int n=0, r;
  char s[r];

  gets(s);
  n = wcount(s);
  printf("%d\n", n);
  
  return 0;
}
