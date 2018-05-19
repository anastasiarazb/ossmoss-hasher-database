#include <stdio.h>

int wcount(char *s)
{
  int flag = 0;
  int count = 0;
  while (*s !='\n') {
    switch (flag) {
      case 0:
        if (*s !=' ') {
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
  return 0;
}
