# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <stdlib.h>

int A[3][3] = { {0} };
char S[10][100] = { {0} };

int min(int a,int b) {
    if (a>b)
        return b;
    else
        return a;
}
int get (char* a, char* b) {
    int i;
    int k=min(strlen(a),strlen(b));
    for (i=k;i>0;i--) {
        int j;
        for (j=0;j<i && b[j]==a[strlen(a)-i+j];j++) {
        }
        if (j==i)
           break;
    }    
    return strlen(b)-i;
}
  
void super(int n)
{
  int i = 0, j = 0;
  for(; i < n; ++i){
    for(j = 0; j < n; ++j)  if(i != j){
      A[i][j] = get(S[i], S[j]);
     // printf("%d %d\n",i,j);
      printf("%d %d %d\n",i, j, A[i][j]);
    }
  }
}

int answer2(int n, int sum, int *B, int prev, int s)
{
  int i = 0, ans = 10000;
  int C[10] = {0};
  for(i = 0 ; i < n; ++i){
   if(B[i] != 0){
      B[i] = 0;
      C[i] = answer2(n, sum + A[prev][i], B, i, s -1);
     B[i] = i + 1;
    }
  }
  if(s == 0) return sum;
  for(i = 0; i < n; ++i){
    if(C[i] != 0 && C[i] < ans)  ans = C[i];
  }
return ans;
}

int answer(int n)
{
  int i = 0, ans = 10000;
  int B[10] = {0};
  int C[10] = {0};
  for(; i < n; ++i) B[i] = i + 1;
  for(i = 0; i < n; ++i){
    B[i] = 0;
    C[i] = answer2(n, strlen(S[i]), B, i, n - 1);
    B[i] = i + 1;
  }
  for(i = 0; i < n; ++i){
    if(C[i] < ans) ans = C[i];
  }
return ans;
}

int main (int argc , char **argv )
{
  int i = 0, n = 0;
  scanf("%d ", &n);
  for(i = 0; i < n; ++i) gets(S[i]);
  super(n);
  printf("%d", answer(n));
  return 0;
}