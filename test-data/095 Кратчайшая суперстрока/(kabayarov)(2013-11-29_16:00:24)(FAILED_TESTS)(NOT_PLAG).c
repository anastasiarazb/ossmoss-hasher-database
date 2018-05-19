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
	int i,r=0;
	if(m==n) return r;
	for(i=0;i<n;i++) ps[i][c][1]++;
	//for()
	for(i=0;i<n;i++) ps[i][c][1]--;
	
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
	int n,i,j,***ps,*pi;
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
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%2d ",ps[i][j][1]);
		printf("\n");
	}
	//////////////////собсно пересчёт////////
	i=Max(ps,n);
	/////////////////////////////////////////
	for(i=0;i<n;i++) {printf("%s ",s[i]); free(s[i]);}
	free(s);
	return 0;
}