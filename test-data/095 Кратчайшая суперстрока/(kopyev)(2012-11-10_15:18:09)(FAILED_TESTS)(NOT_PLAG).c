#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int max=100;
int Dlina(char **uk, char *p, int *a, int n)
{
  int x=0,y=0,m=0,i=0,j=0,k=0,t=0,flag=0;
  for(i=0;i<n;i++)  {
      if(a[i]==1)  {
          a[i]=0;
          x=Dlina(uk,uk[i],a,n);
          a[i]=1;
          t=strlen(p);
          if(t>strlen(uk[i]))  t=strlen(uk[i]);
          for(j=strlen(p)-1;j>=0 && ( strlen(p)-j<=strlen(uk[i]) );j--)  {
              flag=1;
              for(k=0; k<strlen(uk[i]) && k<strlen(p)-j;k++)  {
                  if(p[j+k]!=uk[i][k])  {
                      flag=0;
                      break;
                  }
              }
              if(flag==1) y=strlen(p)-j;
          }
          if(y+x>m) m=y+x;
      }
  }
  return m;
}

int main()
{
  int n=0, i=0, m=0, rezult=0, s=0;
  char **uk;
  scanf("%u\n", &n);
  uk=(char**)malloc(n*sizeof(int));
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
      m=Dlina(uk,uk[i],a,n);
      a[i]=1;
      if (rezult>s-m) rezult=s-m;
  }
  printf("%u\n",rezult);
  for(i=0;i<n;i++)
      free(uk[i]);
  free(uk);
  free(a);
  return 0;
}