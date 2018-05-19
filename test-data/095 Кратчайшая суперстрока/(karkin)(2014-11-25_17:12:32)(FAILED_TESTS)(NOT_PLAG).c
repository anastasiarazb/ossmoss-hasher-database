#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *a,int *b)
{
  int t=*a;
  *a=*b;
  *b=t;
}
 
int next_permut(int *a, int *b)
{
  int n=b-a-1,i=n-1,j=0;
  while(i>=0 && a[i]>a[i+1])
    i--;
  if (i>=0)
  {
    j=i+1;
    while (j<n && a[j+1]>a[i]) j++;
    swap(a+i, a+j);
    for(j=i+1;j<=((n+i)/2);++j)
      swap(a+j, a+n-j+i+1);
    return 1;
  }
  return 0;
}

int Prefix(char *str)
{
  int n=strlen(str),i=1,t=0;
  int p[n];
  p[0]=0;
  while(i<n)
  {
    while(t>0 && str[t]!=str[i])
      t=p[t-1];
    if(str[t]==str[i])  
      t++;
    p[i]=t;
    i++;
  }
  return p[i-1];
}

void scat(char *s1, char *s2)
{
  int n=strlen(s1), m=strlen(s2),j,k;
  char nstr[n+m+2];
  
  for(j=0;j<m;++j)
    nstr[j]=s2[j];
  nstr[m]='$';
  for(j=m+1;j<m+n+1;++j)
    nstr[j]=s1[j-m-1];  
      
  nstr[n+m+1]=0;
  int i=Prefix(nstr);
  
  for(j=n,k=i;j<=n+m-i;j++,k++)
    s1[j]=s2[k];
  s1[j+1]=0;
}

int main()
{
  int n,i;
  scanf("%i\n",&n);
  char *ss[n];
  int p[n],minLen,newStrLen,cStrLen=0;
  for(i=0;i<n;++i)
     ss[i]=(char*)malloc(1000);
  for(i=0;i<n;++i)
  {
    gets(ss[i]);
    p[i]=i;
  }
  char *newStr=(char*)malloc(1000);
  minLen=200;
  do
  {
     newStr[0]=0;
     for(i=0;i<n;++i)
       scat(newStr,ss[p[i]]);
     newStrLen=strlen(newStr);
     
     if(minLen>newStrLen) minLen=newStrLen;
  } while(next_permut(p,p+n));
  for(i=0;i<n;++i)
    free(ss[i]);
  free(newStr);
  printf("%i\n",minLen);
}
