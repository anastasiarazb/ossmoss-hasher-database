#include <stdio.h>
#include <stdlib.h>

int wcount(char *s)
{
  int i = 0, slovo = 0, count = 0;
  while (s[i] != '\0')
  {
    if (s[i] != ' ' && slovo == 0)
    {
      slovo = 1;
      count++;
    }
    else
      if (s[i] == ' ')
        slovo = 0;
      i++;
  }
  printf("%d\n", count);
  return count;
}

void main()
{
  int n = 100;
  char *s = calloc(n, sizeof(char));
  gets(s);
  wcount(s);
  free(s);
}