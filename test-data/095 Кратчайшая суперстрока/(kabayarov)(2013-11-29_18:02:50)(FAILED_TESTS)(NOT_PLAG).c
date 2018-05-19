#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 

int *Prefix(char *s)
{
    int i,l=strlen(s),*pi=(int*)malloc(l*sizeof(int)),t=0;
        pi[0]=t;
	for(i=1;i<l;i++)
	{
		for(;t>0 && s[t]!=s[i];t=pi[t-1]);
		if(s[t]==s[i]) t++;
		pi[i]=t;
	}
	return pi;
}

int Rec(int ***ps, int n, int m, int c)
{
	int i,j,r=0,b;
	if(m==n-1)
	{
		for(i=0;i<c;i++)
			if(ps[c][i][1]==0)
				return ps[c][i][0];
		for(i=c+1;i<n;i++)
			if(ps[c][i][1]==0)
				return ps[c][i][0];
	}
	for(i=0;i<n;i++) ps[i][c][1]++;
	for(i=0;i<n;i++)
	{
		if(ps[c][i][1]==0)
		{
			for(j=0;j<n;j++) ps[c][j][1]++;
			b=Rec(ps,n,m+1,i)+ps[c][i][0];
			if(b>r) r=b;
			for(j=0;j<n;j++) ps[c][j][1]--;
		}
	}
	for(i=0;i<n;i++) ps[i][c][1]--;
	return r;
}

int Max(int ***ps, int n)
{
	int i,r=0,b;
	for(i=0;i<n;i++)
	{		
		b=Rec(ps,n,1,i);
		if(b>r) r=b;
	}
	return r;
}

int main() 
{
	int n,i,j,***ps,*pi,l=0;
	char **s,*b=(char*)malloc(1024*sizeof(char));
	scanf("%d%*c",&n);
	ps=(int***)malloc(n*sizeof(int**));
	s=(char**)malloc(n*sizeof(char*));
	for(i=0;i<n;i++) 
	{
		s[i]=(char*)malloc(512*sizeof(char)); 
		ps[i]=(int**)malloc(n*sizeof(int*));
		for(j=0;j<n;j++) ps[i][j]=(int*)calloc(2,sizeof(int));
		gets(s[i]);
		l+=strlen(s[i]);
	}
	//////////////м. пер.////////////////////
	for(i=0;i<n;i++) 
	{
		for(j=i+1;j<n;j++)
		{
			strcpy(b,s[i]);
			strcat(b,s[j]);
			pi=Prefix(b);
			ps[j][i][0]=pi[strlen(b)-1];
			free(pi);
			strcpy(b,s[j]);
			strcat(b,s[i]);
			pi=Prefix(b);
			ps[i][j][0]=pi[strlen(b)-1];
			free(pi);
		}
	}
	//////////////////собсно пересчёт////////
	printf("%d",l-Max(ps,n));
	/////////////////////////////////////////
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++) free(ps[i][j]);
		free(ps[i]);
		free(s[i]);
	}
	free(ps);
	free(b);
	free(s);
	return 0;
}