#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
  int flag = 0;
  int count = 0;
  if (!(strlen(s) == 0))
  while ((*s !=EOF) && (*s !='\n')) {
    switch (flag) {
      case 0:
        if ((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) {
          count++;
          flag = 1;
        }
        break;
      case 1:
        if (*s ==' ') flag = 0;
        break;
    }
    s++;
  }
  return count;
}

int main()
{
  char string[100000];
  printf("%d \n", wcount(gets(string)));
  return 0;
}