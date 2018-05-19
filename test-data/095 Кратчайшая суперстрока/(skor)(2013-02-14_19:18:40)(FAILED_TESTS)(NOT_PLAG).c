#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int f1( int j, int *dj, int n)
{
  int i;
  for (i = 0; i < n; i += 2)
      if (j == dj[i])
             return 0;
  return 1;
}

int f2( int i, int *dj, int n)
{
  int j;
  for (j = 0; j < n; j += 2)
      if (i == dj[j])
             return dj[j + 1];
  return 666;
}

int maxsum (int **b, int n) 
{
  int i, j, max = 0, y = 0, m[n], dj[n], min;
  for (i = 0; i < 2*n; i++)
      dj[i] = -1;
  for (i = 0; i < n; i++)
      m[i] = 0;
  for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
	    if (b[i][j] > m[i]) 
		   if (f1(j, dj, 2*n) == 1){
		      m[i] = b[i][j];
		      dj[y] = j;
		      y++;
              dj[y] = i;
		      y++;
            }
		    else 
		         if (b[i][j] > b[f2(i, dj, n)][j]){
			        m[i] = b[i][j];
			        dj[f2(i, dj, n)] = i;
			        i = f2(i, dj, n);
                 }
  min = m[1];
  for (i = 0; i < n; i++)
      if (m[i] < min)
	     min = m[i];
  for (i = 0; i < n; i++)
      max += m[i];
  max -= min;
  return max;
}

int main(int argc,char **argv)
{
    int i, j, n, x = 0, t, v;
    scanf("%d", &n);
    char **a = (char**) malloc(n * sizeof(char*)); 
    int **b = (int**) malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
	    b[i] = (int*) malloc(n * sizeof(int));
    for (i = 0; i < n; i++){
        a[i] = (char*) malloc(10 * sizeof(char));
        scanf("\n");
        scanf("%s", a[i]);
    }
    for (i = 0; i < n; i++)
	    for (j = 0; j < n; j++)
	        b[i][j] = 0;
    for (i = 0; i < n; i++)
	    for (j = 0; j < n; j++){
	        t = strnlen(a[i], 10) - 1;
	        v = 0;
	        if (i != j){
		       LOL:
		       if (a[i][strnlen(a[i], 10) - t] == a[j][v])
		          while (a[i][strnlen(a[i], 10) - t] != 0)
			            if (a[i][strnlen(a[i], 10) - t] == a[j][v]){
			               b[i][j] ++;
                           t--;
			               v++;
                        }
			            else
			            {
			                b[i][j] = 0;
			                v = 0;
			                goto LOL;
                         }
               else while (a[i][strnlen(a[i], 10) - t] != 0)
		       {
		            t--;
		            goto LOL;
		       }
            }
	    }
    for (i = 0; i < n; i++)
	    x += strnlen(a[i], 10);
    x -= maxsum( b, n);
    printf("%d", x);
    for (i = 0; i < n; i++){
	    free (a[i]);
	    free (b[i]);
    }
    free (a);
    free (b);
    return 0;
}
