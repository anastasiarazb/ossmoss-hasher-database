#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {return a<b?b:a;}

int **Delta1M(char *s, int size, int ls)
{
        int **d1=(int**)malloc(ls*sizeof(int*)),a=0,j=0;
	d1[0]=(int*)malloc(size*sizeof(int));
	while(a<size) d1[0][a++]=ls;
	d1[0][s[0]]=ls-1;
	for(j=1;j<ls;j++)
	{
		d1[j]=(int*)malloc(size*sizeof(int));
		memcpy(d1[j],d1[j-1],size*sizeof(int));
		d1[j][s[j]]=ls-j-1;
	}
	return d1;
}

int BMSubstM(char *s, char *t, int size)
{
	int ls=strlen(s),lt=strlen(t),**d1=Delta1M(s,size,ls),k=0,i,r=0;
	while(k<lt && k<ls)
	{
		i=ls-1;
		while(t[k]==s[i])
		{
			if(!k) {r=ls-i; break;}
			i--;k--;
		}
		k+=d1[i][t[k]];
		if(r>k) k=r;
	}
	for(k=0;k<ls;k++) free(d1[k]);
	free(d1);
	return r;
}

int MaxIntersectionRec(int **arr, int n, int l, int mem, int flags)
{
	int i=0,nflags=flags-=(1<<l),max=mem,buf;
	for(;i<n;i++,flags>>=1)
	{
		if(!(flags%2)) continue;
		buf=MaxIntersectionRec(arr,n,i,mem+arr[l][i],nflags);
		if(buf>max) max=buf;
	}
	return max;
}

void MaxIntersection(int **arr, int n)
{
	int max=0,i=0,buf,flags=(1<<n)-1;
	for(i=0;i<n;i++)
	{
		buf=MaxIntersectionRec(arr,n,i,0,flags);
		if(buf>max) max=buf;
		
	}
	arr[0][0]-=max; 
}

int main(int argc, char **argv) 
{
	int n,i=0,j,**intersection;
	char (*s)[1024];
	scanf("%d ",&n);
	s=(char(*)[1024])malloc(n*sizeof(char[1024]));
	intersection=(int**)malloc(n*sizeof(int*));
	for(;i<n;i++)
	{
		fgets(s[i],1024,stdin);
		intersection[i]=(int*)calloc(n,sizeof(int));
		j=strlen(s[i])-1;
		intersection[0][0]+=j;  //сумма длин т.к. n>0 а диагонали таблицы пересечений нулевые
		s[i][j]=0;
	}
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			intersection[i][j]=BMSubstM(s[i],s[j],256);
			intersection[j][i]=BMSubstM(s[j],s[i],256);
		}
	MaxIntersection(intersection,n);
	printf("%d\n",intersection[0][0]);
	for(i=0;i<n;i++) free(intersection[i]);
	free(intersection);
	free(s);
	return 0;
}