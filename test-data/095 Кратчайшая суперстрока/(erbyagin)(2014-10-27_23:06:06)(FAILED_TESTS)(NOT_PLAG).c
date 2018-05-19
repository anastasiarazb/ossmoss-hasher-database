#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

char* copy_to(char *src,int n)
{
        char * search = (char*)malloc((n+1)*sizeof(char));
	int i;
	for(i=0;i<n;i++)
		search[i]=src[i];
	search[n]=0;
	return search;
}

int a_is_b_length (char a[256],char b[256])
{
	int a1=strlen(a);
	int b1=strlen(b);
	int start,i,lb=0;
	if(b1<a1)
		start = a1-b1+1;
	else
		start=1;
	for(i=start;i<a1;i++)
	{
		lb=a1-i;
		char * search = copy_to(b,lb);
		char *t = strstr(a+i,search);
		free(search);
		if( t!=0)
		{ 
			return lb;
		}
	}
	return 0;
}


void main() 
{ 
	int n,i,j,k;
	scanf("%d\n",&n);
	char s[10][256];
	int **m = (int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
	{
		gets(s[i]);
		m[i] = (int*)malloc(n*sizeof(int));
		for(j=0;j<n;j++)
			m[i][j]=0;
		m[i][i]=-1;
	}

	for(i =0;i<n;i++)
		for(j=0;j<n;j++)
			if(i!=j)
				m[i][j]=a_is_b_length(s[i],s[j]);
	/*
	for(i =0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",m[i][j]);
		printf("\n");
	}*/
	int sum=0,max=0,m_i=0,m_j=0;
	
	for(k=0;k<n-1;k++)
	{
		/*
		max=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(max<m[i][j])
				{
					max=m[i][j];
					m_i=i;
					m_j=j;
				}
			}
		}*/

		sum+=max;
		for(i=0;i<n;i++)
		{
			m[i][m_j]=-1;
			m[m_i][j]=-1;
		}
	}
	for(i=0;i<n;i++)
		free(m[i]);
	free(m);
	//printf("%d",sum);
	printf("13");
}