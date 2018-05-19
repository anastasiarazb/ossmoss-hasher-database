//wcount.c

#include <stdio.h>
#include <string.h>

int wcount(char*);

int main() {
  char k[1000];
  char *s = gets(k);
  printf("%d\n", wcount(s));
  return 0;
}

int wcount(char* s) {
  int i, k=0;
  if (strlen(s) == 0) return k;
  for(i=0; i<(int)strlen(s); i++)
    if ((s[i] != *(" ")) && (s[i+1] == *(" "))) k++;
  return s[strlen(s)-1] != *(" ") ? ++k : k;
}