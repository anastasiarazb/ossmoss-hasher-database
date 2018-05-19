#include <stdlib.h>
#include <stdio.h>

int wcount(char* s)
{
  int word_count = 0;
  short flag = 0;
  while (*s != '\0') {
    if (' ' == *s)
      flag = 0;
    else
      if (!flag) {
        ++word_count;
	flag = 1;
      }
      ++s;
  }
  return word_count;
}

int main()
{
  char *str = malloc(1000*sizeof(char));
  if (NULL == gets(str))
    return 0;
  printf("%d\n", wcount(str));
  free(str);
  return 0;
}