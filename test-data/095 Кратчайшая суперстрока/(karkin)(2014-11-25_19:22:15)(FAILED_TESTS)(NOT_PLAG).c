#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(int *a,int *b)
{
  int t=*a;
  *a=*b;
  *b=t;
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
  char nstr[n+m+3];
  
  for(j=0;j<m;++j)
    nstr[j]=s2[j];
  nstr[m]='$';
  for(j=m+1;j<m+n+1;++j)
    nstr[j]=s1[j-m-1];  
      
  nstr[n+m+1]=0;
  int i=Prefix(nstr);
  
  for(j=n,k=i;j<=n+m-i;j++,k++)
    s1[j]=s2[k];
}

int superStrLen(int l, int r, int *a, int n, char **s, int *minLen, int maxStrLen)
{
  int i,v=0;
  char *nStr;
  if(l==r)
  {
    char *nStr=malloc(maxStrLen+2);
    nStr[0]=0;
    for(i=0;i<n;++i)
      scat(nStr,s[a[i]]);
    int nStrLen=strlen(nStr);  
    free(nStr);
    
    if(*minLen>nStrLen) (*minLen)=nStrLen;
  }
  else
  {
    for(i=l;i<=r;++i)
    {
      swap(a+l, a+i);
      superStrLen(l+1,r,a,n,s,minLen,maxStrLen);
      swap(a+l, a+i);
    }
  }
  return *minLen;
}

int main()
{
  int n,i;
  scanf("%i\n",&n);
  char *ss[n];
  int p[n],maxStrLen=0;
  for(i=0;i<n;++i)
    ss[i]=(char*)malloc(1000);
    
  for(i=0;i<n;++i)
  {
    gets(ss[i]);
    maxStrLen+=strlen(ss[i]);
    p[i]=i;
  }
  
  int ans = superStrLen(0,n-1, p, n, ss, &maxStrLen,maxStrLen);
  for(i=0;i<n;++i)
    free(ss[i]);
  printf("%i\n",ans);
}
