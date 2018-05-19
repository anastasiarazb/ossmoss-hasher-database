#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int max=100;
int ad_Dlina(char *a, char *b)
{
  int t=0,rezult=0,flag=0,i=0,j=0;
  t=strlen(a);
  if(t>strlen(b))  t=strlen(b);
  for(i=strlen(a)-1;i>=0 && ( strnlen(a)-i<=strlen(b) );i--){
      flag=1;
      for(j=0; j<strlen(b) && j<strlen(a)-i;j++)  {
          if(a[i+j]!=b[j])  {
              flag=0;
              break;
          }
      }
      if(flag==1) rezult=strlen(a)-i;
  }
  return rezult;
}

int Dlina(char **uk, char *p, int *a, int n)
{
  int x=0,y=0,max=0,i=0;
  for(i=0;i<n;i++)  {
      if(a[i]==1)  {
          a[i]=0;
          x=Dlina(uk,uk[i],a,n);
          a[i]=1;
          y=ad_Dlina(p,uk[i]);
          if(y+x>max) max=y+x;
      }
  }
  return max;
}

int main()
{
  int n, i, min, rezult=0, s=0;
  char **uk;
  scanf("%u\n", &n);
  uk=(char**)malloc(n*sizeof(char*));
  int *a;
  a=(int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
      a[i]=0;
  for(i=0;i<n;i++)  {
      uk[i]=(char*)malloc(sizeof(char)*max);
      scanf("%s",uk[i]);
      a[i]=1;
      s+=strnlen(uk[i],max);
  }
  rezult=s;
  for(i=0;i<n;i++)  {
      a[i]=0;
      min=Dlina(uk,uk[i],a,n);
      a[i]=1;
      if (rezult>s-min) rezult=s-min;
  }
  printf("%u\n",rezult);
  for(i=0;i<n;i++)
      free(uk[i]);
  free(uk);
  free(a);
  return 0;
}