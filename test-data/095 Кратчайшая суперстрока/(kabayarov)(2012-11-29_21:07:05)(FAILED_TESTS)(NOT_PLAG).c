#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
/////////////попытка 81/////////////
int prefix(char *s)
{
        int i,l=strlen(s),pi=1;
        for(i=0;i<l/2;i++) if(s[i]!=s[i+l/2]) pi=0;
	return pi;
}

void vongola(int *a, int m , int n, int *p, int *judaime, int **gokudera)
{
	int i,j,*q,max=0;
	if(m==0)
	{
		for(i=0;i<n-1;i++) 
			max+=gokudera[p[i]][p[i+1]];
		if(max>*judaime) *judaime=max;
	}
	else
	{
		q=(int *)malloc((m-1)*sizeof(int));
		for(i=0;i<m;i++)
		{
			p[n-m]=a[i];
			j=0;
			while(a[i]!=a[j])
			{
				q[j]=a[j];
				j++;
			}
			for(j; j<m-1; j++)
			{
				q[j]=a[j+1];
			}
			vongola(q,m-1,n,p,judaime,gokudera);
		}
		free(q);
	}
}

int main()
{
	char s[10][1024], t[2048];
	int n,i,g,k,**a,l=0,li,lj,pi,judaime=0,*b,*p;
	scanf("%d",&n);
	a=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++) 
	{
		a[i]=(int*)malloc(n*sizeof(int));
		for(g=0;g<n;g++) a[i][g]=0;
	}

	for(i=0;i<n;i++) scanf("%s",s[i]);
	for(i=n;i<10;i++) strcpy(s[i],"");
	for(i=0;i<n;i++)
	{
		li=strlen(s[i]);
		l+=li;
		for(g=0;g<n;g++)
		{
			if(i==g) continue;
			lj=strlen(s[g]);
			(lj>=li) ? (k=li) : (k=lj);
			for(k; k>0; k--)
			{
				strcpy(t,(s[i]+li-k));
				strncat(t,s[g],k);
				pi=prefix(t);
				if(pi) {a[i][g]=k; break;}
			}
		}
	}
	b=(int *)malloc(n*sizeof(int));
	p=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++) b[i]=i;
	vongola(b,n,n,p,&judaime,a);
	printf("%d",l-judaime);
	free(b);
	free(p);
	for(i=0;i<n;i++) free(a[i]);
	free(a);
	return 0;
} 