#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 

void Prefix(char *s, int* pi)
{
        int i,l=strlen(s),t=0;
	pi[0]=t;
	for(i=1;i<l;i++)
	{
		for(;t>0 && s[t]!=s[i];t=pi[t-1]);
		if(s[t]==s[i]) t++;
		pi[i]=t;
	}
}

int Rec(int **ps, int n, int m, int c, int* xs)
{
	int i,r=0,b;
	xs[c]++;
	if(m==n-1)
	{
		for(i=0;i<n;i++)
			if(xs[i]==0)
			{xs[c]--; return ps[c][i];}
	}	
	for(i=0;i<n;i++)
	{
		if(xs[i]==0)
		{
			b=Rec(ps,n,m+1,i,xs)+ps[c][i];
			if(b>r) r=b;
		}
	}
	xs[c]--;
	return r;
}

int Max(int **ps, int n)
{
	int i,r=0,b,*xs=(int*)calloc(n,sizeof(int*));
	for(i=0;i<n;i++)
	{		
		b=Rec(ps,n,1,i,xs);
		if(b>r) 
			r=b;
	}
	free(xs);
	return r;
}

int main() 
{
	int n,i,j,**ps,*pi=(int*)malloc(1024*sizeof(int)),l=0;
	char **s,*b=(char*)malloc(1024*sizeof(char));
	scanf("%d%*c",&n);
	ps=(int**)malloc(n*sizeof(int*));
	s=(char**)malloc(n*sizeof(char*));
	for(i=0;i<n;i++) 
	{
		s[i]=(char*)malloc(512*sizeof(char)); 
		ps[i]=(int*)calloc(n,sizeof(int));
		gets(s[i]);
		l+=strlen(s[i]);
	}
	//////////////м. пер.////////////////////
	for(i=0;i<n;i++) 
	{
		for(j=i+1;j<n;j++)
		{
			strcpy(b,s[i]);
			strcat(b," ");
			strcat(b,s[j]);
			Prefix(b,pi);
			ps[j][i]=pi[strlen(b)-1];
			strcpy(b,s[j]);
			strcat(b," ");
			strcat(b,s[i]); 
			Prefix(b,pi);
			ps[i][j]=pi[strlen(b)-1];
		}
	}
	//////////////////собсно пересчёт////////
	printf("%d",l-Max(ps,n));
	/////////////////////////////////////////
	for(i=0;i<n;i++)
	{
		free(ps[i]);
		free(s[i]);
	}
	free(ps);
	free(b);
	free(s);
	free(pi);
	return 0;
}