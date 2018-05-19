#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int summ=0;
void permutrec(int q, int m, int *p,int **a, int nel)
{
  int i,s,q2=q;
  if (m==0)
  {
    s=0;
    /*for(i=0;i<nel;i++)
      printf("%d ",p[i]);
    printf("\n");*/
    for(i=1;i<nel;i++)
      s+=a[p[i]][p[i-1]];
    if (s>summ)
      summ=s;
  }
  else
    for(i=0;i<nel;i++,q2>>=1)
      if (q2&1)
      {
        p[nel-m]=i;
        permutrec(q&~(1<<i),m-1,p,a,nel);
      }
}

int main()
{
  unsigned int q=-1;
  int **a,n,i,j,*p,x,z,m,leni,lenj,c,y,k;
  char **s;
  scanf("%d\n",&n);
  p=(int*)malloc(n*sizeof(int));
  a=(int**)malloc(n*sizeof(int*));
  s=(char**)malloc(n*sizeof(char*));
  for(i=0;i<n;i++)
  {
    a[i]=(int*)malloc(n*sizeof(int));
    s[i]=(char*)malloc(1000*sizeof(char));
    gets(s[i]);
  }
  for (i=0;i<n;i++)
    for (j=0;j<n;j++)
    {
      if (i==j)
        a[i][j]==0;
      else 
      {
	y=0;
	leni=strnlen(s[i],100);
	lenj=strnlen(s[j],100);
	for (c=leni-1;c>=0;c--)
	  if (s[i][c]==s[j][0])
	  {
	    z=0;
	    m=1;
	    for (x=c+1;x<leni;x++)
	    {
	      if (s[i][x]!=s[j][m])
	      {
		z++;
		break;
	      }
	      m++;
	    }
	    if ((z==0) && (m>y))
	      y=m;
	  }
	  a[i][j]=y;
      }
    }
  
  /*for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
      printf("%d ",a[i][j]);
    printf("\n");
  }*/
  k=0;
  for(i=0;i<n;i++)
    k+=strlen(s[i]);
  permutrec(q,n,p,a,n);
  
  printf("%d\n",k-summ);
  
  for(i=0;i<n;i++)
  {
    free(a[i]);
    free(s[i]);
  }
  free(a);
  free(s);
  free(p);
  return 0;
}