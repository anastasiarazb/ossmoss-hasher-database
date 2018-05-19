#include <stdio.h> 
#include <string.h>

int min = 0;
char prom[200];

char *compare(char *elem, char *comp)
{
  int i, lenE = strlen(elem), j, lenC = strlen(comp), k = 0;
  j = lenE - 1;
  strcpy(prom, elem);
  for (i = lenC - 1; i >= 0; i--) {
    while (j >= lenE - lenC) {
      if (j == lenE - lenC) {
        i = i + k - 1;
	j = lenE - 1;
	k = 0;
      }
      if ((j == lenE - 1) || (elem[j] == comp[i]))
	if (prom[j] == comp[i]) {
	  j--;
	  k++;
	  break;
	}
	else {
	  k = 0;
	  break;
	}
      else { 
	i = i + k - 1;
	j = lenE - 1;
	k = 0;
      }
    }
  }
  prom[lenE - k] = '\0';
  strcat(prom, comp);
  return prom;
}

void *searchstr(char **arr, int *ref, char *elem, int n, int contrl)
{
  
  int i, j;
  char loc[200];
//  printf("%d ", contrl);
  if (contrl == n) {
  //  printf("%s\n", elem);
    if ((strlen(elem) < min) || (min == 0))
      min = strlen(elem);
  }
 // printf("%s ", elem);
 // for (i = 0; i < n; i++)
  //  printf("%d ", ref[i]);
 // printf("\n");
  for (j = 0; j < n; j++) {
    if (ref[j] == 0) {
      ref[j] = 1;
      strcpy(loc, compare(elem, arr[j]));
      searchstr(arr, ref, loc, n, (contrl+1));
      ref[j] = 0;
      strcpy(loc, elem);
    //  elem[strlen(elem)-strlen(arr[j])] = '\0';
    }
  }
} 

int main(int argc, char **argv)
{
  int n, i;
  scanf("%d ", &n);
  char *point[n];
  char strs[n][100];
  char empty[1];
  int check[n];
  empty[0] = '\0';
  for (i = 0; i < n; i++) {
    gets(strs[i]);
    point[i] = &strs[i][0];
    check[i] = 0;
  }
  searchstr(point, check, empty, n, 0);
  printf("%d\n", min);
 // printf("%s\n", point[0]);
 // printf("%s ", compare(point[0], point[1]));
  return 0;
}