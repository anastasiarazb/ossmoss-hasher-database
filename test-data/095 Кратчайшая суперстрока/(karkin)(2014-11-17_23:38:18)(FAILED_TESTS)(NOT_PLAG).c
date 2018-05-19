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
  else return 0;
}

char *scat(char *s1, char *s2)
{
  int s1Len=strlen(s1), s2Len=strlen(s2), i=0,j=0,k=0;
  for(k=0;k<s1Len;k++)
    if(s1[k]==s2[0])
    {
      i=k; j=0;
      while(s1[i]==s2[j])
      {
        i++;
        j++;
        if(i>=s1Len)
        {
            strncat(s1, s2+s1Len-k,s2Len-s1Len+k);
	   return s1;
	}
      }
    }
  strncat(s1,s2,s2Len);
  return s1;
}

int main()
{
  int n,i;
  scanf("%i\n",&n);
  char *ss[n];
  int p[n],maxLRS=0,minLen,newStrLen,cStrLen=0;
  for(i=0;i<n;++i)
     ss[i]=(char*)malloc(50);
  for(i=0;i<n;++i)
  {
    gets(ss[i]);
    maxLRS+=strlen(ss[i]);
    p[i]=i;
  }
  char *newStr=(char*)malloc(maxLRS);
  minLen=maxLRS;
  do
  {
     
     strcpy(newStr,"");
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
