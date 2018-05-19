# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int super[10][10];
char s[10][10000];
int arr[100], ar[100], min1 = -10;
int mins[10];
int conc(int n , int m)
{
  int i = 0, j = 0, k = 0, l = 0, k2 = 0;
  for (i = 0; i < strlen(s[m]);i++){
    for (j = 0; j <= i && strlen(s[n]) - 1 - i + j >=0   ; j++){
      if (s[m][j] != s[n][strlen(s[n]) - 1 - i + j]){
        k2 = k2 - j;
	break;     
      }else{
	k2++;
      }
      if (j == i){
	k = k2;
	k2 = 0;
      }	
    }
  }
  return strlen(s[m]) -  k;
}
int superstr(int l,  int n)
{
    int i;
    int  min;
    if (l == (n-1)) { 
       min = 0;
        for (i = 0;i < n - 1;i++) {
            min += super[ar[i]][ar[i+1]];
        }
        min +=strlen(s[ar[0]]);
	if (min < min1 || min1 < 0) min1 = min;
    }
    for (i=0;i<n;i++) {
        if (arr[i] != 0) {
            arr[i]= 0;
	    ar[l + 1] = i;
            superstr( l + 1, n);
            arr[i]= i + 1;
        }
    }
    return min1;
}

void superstroka(n)
{
  int i;
 for (i=0;i<n;i++) {
        arr[i]=i + 1;
    }
    for (i=0;i<n;i++) {
        arr[i]=0;
	ar[0] = i;
        mins[i] = superstr( 0,  n);
        arr[i]=i + 1;
    }
}

    

int main (int argc , char **argv )
{
  int x, i , n, min, j;
  scanf("%d ", &n);
  for(i = 0; i < n; ++i) gets(s[i]);
  for(i = 0; i < n; ++i){
    for(j = 0; j < n; ++j)  if(i != j){
      super[i][j] = conc(i, j);
    }
  }
  superstroka(n);
 min = mins[0];
 for (i = 1; i < n; i++) if (mins[i] < min) min = mins[i]; 
  printf("%d", min);
  return 0;
}