#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
  int flag = 0;
  int flag1 = 0;
  int count = 0;
  while (*s != 0) {
    if (flag1) s++;
    else flag1 = 1;
    switch (flag) {
      case 0:
        if ((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) {
          count++;
          flag = 1;
        }
        break;
      case 1:
        if (!((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))) flag = 0;
        break;
    }
  }
  return count;
}

int main()
{
  char string[1000];
  printf("%d \n", wcount(gets(string)));
  return 0;
}