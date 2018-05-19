#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
  int i,n,**a,q,m,p,k,j,x,c,leni,lenj;
  char **s;
  scanf("%d",&n);
  a=(int**)malloc((n+1)*sizeof(int*));
  for (i=1;i<=n; i++)
    a[i]=(int*)malloc((n+1)*sizeof(int));
  s=(char**)malloc((n+1)*sizeof(char*));
  for (i=0; i<n+1; i++)
  {
    s[i]=(char*)malloc(100*sizeof(char));
    gets(s[i]);
  }

  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
      if (i==j)
        a[i][j]==0;
      else 
      {
	p=0;
	leni=strnlen(s[i],100);
	lenj=strnlen(s[j],100);
	for (c=leni-1;c>=0;c--)
	  if (s[i][c]==s[j][0])
	  {
	    q=0;
	    m=1;
	    for (x=c+1;x<leni;x++)
	    {
	      if (s[i][x]!=s[j][m])
	      {
		q++;
		break;
	      }
	      m++;
	    }
	    if ((q==0) && (m>p))
	      p=m;
	  }
	
	
	for (c=lenj-1;c>=0;c--)
	  if (s[j][c]==s[i][0])
	  {
	    q=0;
	    m=1;
	    for (x=c+1;x<lenj;x++)
	    {
	      if (s[j][x]!=s[i][m])
	      {
		q++;
		break;
	      }
	      m++;
	    }
	    if ((q==0) && (m>p))
	      p=m;
	  }

	  a[i][j]=p;
      }
    }
    k=1;
    for (i=2;i<=n;i++)
    {
      for (x=1;x<=k;x++)
	a[i][x]=0;
      k++;
    }
    k=0;
    p=0;
    for (i=1; i<=n;i++)
      k+=strnlen(s[i],100);
    
    for (i=n;i>=1;i--)
    {
      p=0;
      x=1;
      for (j=1;j<=n;j++)
	if (a[j][i]>p)
	{
	  p=a[j][i];
	  x=j;
	}
	k-=p;
	a[i][x]=0;
    }
    for (i=1;i<=n;i++)
    {
      for (j=1;j<=n;j++)
	printf("%d ",a[i][j]);
      printf("\n");
    }
    
    
    printf("%d\n",k);

  for (i=1; i<=n; i++)
    free(a[i]);
  for (i=1; i<=n; i++)
    free(s[i]);
  free(a);
  free(s);
  return 0;
}