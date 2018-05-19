#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s);

int main(int argc, char** argv) {
    char str[255];
    gets(str);
    printf("%d\n", wcount(str));
    return 0;
}

int wcount(char *s) {
  int i, kol_slov = 0, kol_bukv_v_slove = 0;
  char bukva;
  for (i = 0; ; i++)
  {
    bukva = s[i];
    if (bukva == ' ' || bukva == '\t' || bukva == '\n' || bukva == '\0')
    {
      if (kol_bukv_v_slove != 0)
        kol_slov++;
      if (bukva == '\0')
	break;
      kol_bukv_v_slove = 0;
    }
    else {
      kol_bukv_v_slove = 1;
    }
  }
  return kol_slov;
}