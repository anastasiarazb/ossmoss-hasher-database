#include <stdio.h>
#include <stdlib.h>

#define IN 1                 /* показывает, находимся ли мы внутри */
#define OUT 0		/* или снаружи слова                  */

int wcount(char *s)
{
  int nw, state;
  char c;
  state = OUT;
  nw = 0;
  while (*s != '\0')
  {
    if (*s == ' ')
      state = OUT;
    else if (state == OUT)
    {
      state = IN;
      ++nw;
    }
    s++;
  }
  
  return nw;
}

int main()
{
  int Nw;
  char *stroka = (char*)malloc(sizeof(char)*1000);
  gets(stroka);
  Nw = wcount(stroka);
  printf("%d\n", Nw);

  free(stroka);

  return 0;
}