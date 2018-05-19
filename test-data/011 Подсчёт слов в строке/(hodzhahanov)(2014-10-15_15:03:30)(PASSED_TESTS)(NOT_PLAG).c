#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #define N 50
int wcount(char *s)
{
  int a;
  a = 0;
  int b;
  if (*s == 0) return 0;
  else {
  if (*s != ' ') a++;
  for( b = 0; b < N; b++) 
        {        
   	 if (*(s+b*sizeof(char)) == ' ' &&  *(s+(b+1)*sizeof(char)) != ' ' ) a++ ;
         if (*(s+b*sizeof(char)) == ' ' &&  *(s+(b+1)*sizeof(char)) == 0 ) a--;
	}
	return a;
}
}

main(int argc, char **argv)
{
	int a ;
  char *s;
  s = (char *)malloc(N*sizeof(char)) ;
  memset (s, 0, sizeof(char) * N);
  gets(s) ;
  a = wcount(s) ;
  printf("%d", a);
  free(s) ;
}