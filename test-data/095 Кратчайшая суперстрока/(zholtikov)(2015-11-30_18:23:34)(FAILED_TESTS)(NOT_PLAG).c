#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Overlap(char *one, char *two)
{
  int i,j, over=0, max=0;
  for (i = 1; one[i]!=0; ++i, over = 0)
  {
    for (j = i; one[j]!=0 && two[over]!=0; ++j, ++over)
      if (one[j] != two[over])
      {
        over = 0;
        break;
      }
    if (over > max)
      max = over;
  }
  return max;
}


int main()
{
  int n, i, j, num, maxover, one, two, super;
  scanf("%d", &n);
  char **arr = calloc(n, sizeof(char*));
  for (i = 0; i < n; ++i)
  {
    arr[i] = calloc(100, sizeof(char));
    scanf("%s", arr[i]);
  }
	
  for (num = 1; num < n; ++num)
  {
    for (i = 0, maxover = -1; i < n; ++i)
      for (j = 0; j < n; ++j)
        if (i != j && arr[i][0] && arr[j][0])
	{
	  int curov = Overlap(arr[i], arr[j]);
	  if (curov > maxover)
	    max = curov, one = i, two = j;
	}
    arr[one][strlen (arr[one])- maxover]='\0';
    strcat(arr[one],arr[two]);
    arr[two][0]='\0';
    super = one;
  }
  
  printf("%d\n", (int) strlen(arr[super]));
  
  for (i = 0; i < n; ++i)
    free(arr[i]);
  free(arr);
  return 0;
}