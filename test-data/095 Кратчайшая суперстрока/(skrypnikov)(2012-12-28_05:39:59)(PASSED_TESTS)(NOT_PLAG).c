
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

int maxCross(int **m,int n);
int cross(char *a,char *b);

int main()
{        int n, i, j, **m, O=0;
	char **p;
	scanf ("%d", &n);
	p=(char**)malloc(n*sizeof(char *));
	for (i=0;i<n;i++)
	{	p[i]=(char*)malloc(25*sizeof(char));
		scanf("%s",p[i]);
		O+=strlen(p[i]);
	}
	m=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{	m[i]=(int*)malloc(n*sizeof(int));
		for(j=0;j<n;j++)
		  m[i][j]=0;
	}
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	  {	if(i==j)
		  continue;
		m[i][j]=cross(p[i],p[j]);
	  }
	printf ("%d\n", O-maxCross(m,n));
	for(i=0;i<n;i++)
	{	free(p[i]);
		free(m[i]);
	}
	free(p);
	free(m);
	return 0;
}

int cross( char *a, char *b)
{	int t=0, i, count, len, p[100];
	char s[100];
	s[0]='\0';
	strcat(s, a);
	strcat(s, "$");
	strcat(s, b);
	len=strlen(s);
	for (i=0; i<len; i++)
	  p[i]=0;
	for(i=1;i<strnlen(s,1000);i++)
	{	while ((t>0) && (s[t]!=s[i]))
		  t=p[t-1];
		if(s[t]==s[i])
		  t++;
		p[i]=t;
	}
	return p[len-1];
}

int maxCross(int **m,int n)
{	int i,j,k,f=0,d,min,max,flag,*p,*u,X=0;
	p=(int*)malloc(n*sizeof(int));
	u=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++) 
	{	p[i]=i;
		u[i]=0;
	}
	while(0==0)
	{	max=0;
		for(i=0;i<n-1;i++) 
		  max+=m[p[i]][p[i+1]];
		if(max>X)
		  X=max;
		flag=0;
		for (i=n-2; i>=0; i--)
		  if (p[i]<p[i+1])
		  {	flag=1;
			break;
		  }
		if (flag==0)
		  break;
		d=p[i+1];
		for (j=i+1; j<n; j++)
		{	if (((p[j]-p[i])<=d) && (p[i]<p[j]))
			min=j;
		}
		d=p[i];
		p[i]=p[min];
		p[min]=d;
		for (j=i+1; j<n; j++) 
		  u[j]=p[j];
		for (j=n-1;j>=i+1;j--) 
		  p[n+i-j]=u[j];
	}
	free(p);
	free(u);
	return X;
}
