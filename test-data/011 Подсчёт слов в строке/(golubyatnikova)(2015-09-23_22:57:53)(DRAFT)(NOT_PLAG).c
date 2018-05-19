#include<stdio.h>
#include <string.h>
#define LEN 1000

int wcount(char* s) {
  int i, words = -1;
  char pre=32;
  for (i = 0; i < strlen(s); i++) {
    if ((pre==32) && (s[i]!=32)) words++;
    pre=s[i];
  }
  return words+1;
}

int main(void) {
  char strstr[LEN];
    gets(strstr);
    printf("%d", wcount(strstr));
    return 0;
}