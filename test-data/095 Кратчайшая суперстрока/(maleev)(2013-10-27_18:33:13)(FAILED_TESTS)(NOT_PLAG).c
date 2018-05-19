#include <stdio.h> 
#include <string.h>

int min = 0;
char prom[10000];

char *compare(char *elem, char *comp)
{
  int i, len = strlen(elem) - 1, j;
  j = len;
  strcpy(prom, elem);
  for (i = strlen(comp) - 1; i >= 0; i--) {
    if (j < 0) 
      return comp;
    if (j > len)
      j = len;
    while (j <= len) {
      if (comp[i] == elem[j]) {
        j--;
	break;
      }
      else 
	j++;
    }
  }
  prom[j+1] = '\0';
  strcat(prom, comp);
  return prom;
}

void *searchstr(char **arr, int *ref, char *elem, int n, int contrl)
{
  
  int i, j;
  if (contrl == n)
    if ((strlen(elem) < min) || (min == 0))
      min = strlen(elem);
  for (j = 0; j < n; j++) {
    if (ref[j] == 0) {
      ref[j] = 1;
      searchstr(arr, ref, compare(elem, arr[j]), n, (contrl+1));
      ref[j] = 0;
    }
  }
} 

int main(int argc, char **argv)
{
  int n, i;
  scanf("%d ", &n);
  char *point[n], strs[n][100], empty[1];
  int check[n];
  empty[0] = '\0';
  for (i = 0; i < n; i++) {
    gets(strs[i]);
    point[i] = &strs[i][0];
    check[i] = 0;
  }
  searchstr(point, check, empty, n, 0);
  printf("%d\n", min);
  return 0;
}