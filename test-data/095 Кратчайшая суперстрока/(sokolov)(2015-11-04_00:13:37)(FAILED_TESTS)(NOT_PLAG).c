#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *concat(char *s1,char *s2)
{
        int i,j=0,k,l1,l2,q,j2;
	l1=strlen(s1);
	l2=strlen(s2);
	for(i=0;i<l1;++i)
	{	
		j=1;
		if(s1[i]==s2[0] && l2!=1)
		{
			for(k=i+1;k<i+l2;++k)
			{
				if(s1[k]!=s2[j])	
					break;
				
				else if(k+1>=l1)
				{	++j;
					j2=j;
					for(q=k+1;q<k+l2-j2+1;++q)
					{
						s1[q]=s2[j];
						++j;
					}
					s1[k+l2-j2+1]=0;
					return s1;
				}
				else if(j+1>=l2)
				{
					
					return s2;
				}
				++j;
			}
		}
		else if(s1[i]==s2[0])
		{
			
			return s2;
		}
	}
		return strcat(s1,s2);
}

	
main()
{        
        int n,i=0,s=0,j=0,l=0,suml=0;
        scanf("%d ", &n);
	char *p[n];
	char *f;
	char *h;
	char *g;
	char *p2;
	for (i=0;i<n;++i)	
	{
		p[i]=(char*) malloc(256*sizeof(char));	
		gets(p[i]);
		suml+=strlen(p[i]);
	}
	char *ss=(char*)malloc((suml+1)*sizeof(char));
	h=(char*)malloc((suml+1)*sizeof(char));
	f=(char*)malloc((suml+1)*sizeof(char));
	g=(char*)malloc((suml+1)*sizeof(char));
	p2=(char*)malloc(256*sizeof(char));
	*ss=0;
	strcpy(f,concat(ss,p[0]));
	strcpy(ss,f);
	for(i=0;i<n-1;++i)
	{	
		strcpy(g,ss);
		strcpy(p2,p[i+1]);
		strcpy(h,concat(p[i+1],ss));
		strcpy(f,concat(g,p2));
		strcpy(ss,f);
	
		if(strlen(ss)>=strlen(h))
			{	//printf("%s\n", ss);
				strcpy(ss,h);	
				
				//printf("%s\n", ss);
			}		
	}
	s=strlen(ss);	
	free(ss);
	free(h);	
	free(f);
	free(g);
	free(p2);
	for (i=0; i<n;++i)
		free(p[i]);
	printf("%d\n", s);
	return 0;
}