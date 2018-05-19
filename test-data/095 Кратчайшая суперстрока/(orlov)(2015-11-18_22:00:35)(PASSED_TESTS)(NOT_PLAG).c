#include <stdio.h>
#include <string.h>
#include <malloc.h>
char* substring(char* s, int left, int right)
{
  char* res = calloc(right-left + 1, sizeof(char));
  memcpy(res, &s[left], right - left);
  return res;
}

int overlap(char* s1, char* s2)
{
  char *suff, *pref;
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  int overlap = 0, i, j;
  for (i = len1 - 1, j = 1; i > 0 && j < len2; i--, j++)
  {
    suff = substring(s1, i, strlen(s1));
    pref = substring(s2, 0, j);
    if (strcmp(suff, pref) == 0) overlap = j;
    free(suff);
    free(pref);
  }
  return overlap;
}

void merge(char* s1, char* s2, int len, char* a)
{
  int lenr = strlen(s1) + strlen(s2) - len;
  char* res = calloc(lenr + 1, sizeof(char));
  memcpy(res, s1, strlen(s1) - len);
  strcat(res, s2);
  memcpy(a, res, lenr);
  a[lenr] = 0;
  free(res);
}


int main()
{
  int n, i;
  scanf("%d\n", &n);
  char** array = calloc(n, sizeof(char*));
  for (i = 0; i < n; i++)
  {
    array[i] = calloc(100, sizeof(char));
    gets(array[i]); //инициализация
  }
  int max, o, j, it;
  char *one, *two;
  for (it = 1; it < n; it++)
  {
    max = -1;
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
        if (i != j)
        {
          if (array[i][0] && array[j][0]) o = overlap(array[i], array[j]);
          else o = -1;
          if (o > max)
          {
            max = o;
            one = array[i];
            two = array[j];
          }
        }
    merge(one, two, max, one);
    *two = 0;
  }
  printf("%d\n", strlen(one));
  for (i = 0; i < n; ++i)
    free(array[i]);
  free(array);
  return 0;
}