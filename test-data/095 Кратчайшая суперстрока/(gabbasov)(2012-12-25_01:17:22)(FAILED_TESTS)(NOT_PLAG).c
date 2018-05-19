#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str(char *a,char *b)
{
        int c,i,n;
	if (strlen(a)>strlen(b))
		n=strlen(b);
	else
		n=strlen(a);
	for (i=1;i<n;i++)
		if (strncmp(a+strlen(a)-i,b,i)==0)
			c=i;
	return c;
}

void bmtrx(char **s,int n,int **a)
{
	int i,j;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			if (i!=j)
				a[i][j]=str(s[i],s[j]);
			else
				a[i][j]=0;
}

int mx(int **a,int n,int *c1,int *c2)
{
	int i,j,max=a[0][0];
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			if (a[i][j]>max)
				*c1=i,*c2=j,max=a[i][j];
	return max;
}

int mtrx(int **a,int n)
{
	int c1,c2,max,i,j=0,q=0;
	max=mx(a,n,&c1,&c2);
	while ((max!=0)&&(j<n-1))
	{
		j++;
		q+=max;
		for (i=0;i<n;i++)
			a[c1][i]=0,a[i][c2]=0;
		max=mx(a,n,&c1,&c2);
	}
	return q;
}

int main()
{
	char **s;
	int **a,n,i,j=0,q;
	scanf("%d\n",&n);
	a=(int**)malloc(sizeof(int*)*n);
	s=(char**)malloc(sizeof(char*)*n);
	for (i=0;i<n;i++)
	{
		a[i]=(int*)malloc(sizeof(int)*n);
		s[i]=(char*)malloc(sizeof(char)*100);
	}
	for (i=0;i<n;i++)
	{
		gets(s[i]);
		j+=strlen(s[i]);
	}
	bmtrx(s,n,a);
	q=mtrx(a,n);
	j-=q;
	printf("%d",j);
	for (i=0;i<n;i++)
	{
		free(a[i]);
		free(s[i]);
	}
	free(a);
	free(s);
	return 0;
}