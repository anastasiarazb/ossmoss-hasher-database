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

int Prefix(char *str1, char *str2)
{

  int n=strlen(str1), m=strlen(str2),k,t,i;
  char nstr[n+m+3];
  
  for(i=0;i<m;++i)
    nstr[i]=str2[i];
  nstr[m]='$';
  for(i=m+1;i<m+n+1;++i)
    nstr[i]=str1[i-m-1];     
  nstr[n+m+1]=0;
  n+=m+1;
  
  int p[n];
  p[0]=0;
  i=1;
  t=0;
  while(i<n)
  {
    while(t>0 && nstr[t]!=nstr[i])
      t=p[t-1];
    if(nstr[t]==nstr[i])  
      t++;
    p[i]=t;
    i++;
  }
  
  return p[i-1];
}

int main()
{
  int n,i,j;
  scanf("%i\n",&n);
  char ss[n][1000];
  int p[n],sumInt,maxSumInt=0,sumLen=0,prefixes[n][n];
  for(i=0;i<n;++i)
  {
    gets(ss[i]);
    p[i]=i;
  }
  for(i=0;i<n;++i)
    for(j=0;j<n;++j)
      if(i!=j)
         prefixes[i][j]=Prefix(ss[i],ss[j]);
  do
  {
     sumInt=0;
     for(i=1;i<n;++i)
       sumInt+=prefixes[p[i-1]][p[i]]; 
    
     if(sumInt>maxSumInt) maxSumInt=sumInt;
  } while(next_permut(p,p+n));
  for(i=0;i<n;++i)    
    sumLen+=strlen(ss[i]);
  
  printf("%i\n",sumLen-maxSumInt);
}
