#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int next(int *x, int q, int n)
{
        int j,i=n-1,c;
	while(i>0 && x[i]>x[i+1])
		--i;
	if(i>0)
	{
		j=i+1;
		while(j<n && x[j+1]>x[i])
			++j;
		c=x[i];
		x[i]=x[j];
		x[j]=c;
		for(j=i+1; j<=(n+i)/2;++j)
		{
			
			c=x[j];
			x[j]=x[n-j+1+i];
			x[n-j+1+i]=c;
		}
		q=1;
	}
	else q=0;
	return q;
}
char *concat(char *s1,char *s2)
{
	//printf("%s %s\n", s1, s2);
	int i,j=0,k,l1,l2,q,j2;
	l1=strlen(s1);
	l2=strlen(s2);
	for(i=0;i<l1;++i)
	{	
		j=1;
		if(s1[i]==s2[0] && l2!=1 && l1!=1)
		{
			for(k=i+1;k<i+l2+1;++k)
			{
				if(j>=l2 && k<=l1)
				{
					
					return s1;
				}
				else if(k>=l1 )
				{	 j2=j;
					if(s1[k-1]==s2[0])
					{	--j;
						for(q=k-1;q<k+l2-j2;++q)
						{
							s1[q]=s2[j];
							++j;
						}
						s1[k+l2-j2]=0;
						return s1;
					}
					else
					{	
						for(q=k;q<k+l2-j2;++q)
						{
							s1[q]=s2[j];
							++j;
						}
						s1[k+l2-j2]=0;
						return s1;
					}
				}
				
				else if(s1[k]!=s2[j])	
					 break;
				
				
				++j;
			}
		}
		else if(s1[i]==s2[0])
		{
			if (l2>=l1)
				return s2;
			else
				return s1;
		}
	}
		return strcat(s1,s2);
}

int main()
{
	int i,n,q=1;
	scanf("%d", &n);
	int x[n+1];
	int s=0,j=0,l=0,suml=0,k=2561;
        scanf("%d ", &n);
	char *p[n];
	char *f;
	for (i=0;i<n;++i)	
	{
		p[i]=(char*) malloc(256*sizeof(char));	
		gets(p[i]);
		suml+=strlen(p[i]);
	}
	char *ss=(char*)malloc((suml+1)*sizeof(char));
	f=(char*)malloc((suml+1)*sizeof(char));
	for(i=1;i<=n;++i)
		x[i]=i;
	do
	{
		strcpy(ss,p[x[1]-1]);
		for(i=1;i<n;++i)
		{
			strcpy(f,concat(ss,p[x[i+1]-1]));
			strcpy(ss,f);
		}
		if(strlen(ss)<k)
			k=strlen(ss);
		q=next(x,q,n);
	} while(q!=0);
	free(ss);
	free(f);
	for (i=0; i<n;++i)
		free(p[i]);
	printf("%d\n", k);
	return 0;
}