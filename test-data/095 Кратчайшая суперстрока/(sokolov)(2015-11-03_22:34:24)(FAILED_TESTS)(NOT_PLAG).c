#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *concat(char *s1,char *s2)
{
        int i,j=0,k,l1,l2,q,j2;
	l1=strlen(s1);
	l2=strlen(s2);
	char *s=(char*)malloc((l1+l2+1)*sizeof(char));
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
					strcpy(s,s1);
					for(q=k+1;q<k+l2-j2+1;++q)
					{
						s[q]=s2[j];
						++j;
					}
					s[k+l2-j2+1]=0;
					return s;
				}
				else if(j+1>=l2)
				{
					strcpy(s,s2);
					return s;
				}
				++j;
			}
		}
		else if(s1[i]==s2[0])
		{
			strcpy(s,s2);
			return s;
		}
	}
		strcpy(s,strcat(s1,s2));
		return s;
}

	
main()
{        
        int n,i=0,s=0,j=0,l=0;
        scanf("%d ", &n);
	char *p[n];
	char *f;
	char *h;
	for (i=0;i<n;++i)	
	{
		p[i]=(char*) malloc(256*sizeof(char));	
		gets(p[i]);
	}
	f=p[0];	
	for(i=0;i<n-1;++i)
	{	
		h=concat(p[i+1],f);
		f=concat(f,p[i+1]);
		
		if(strlen(f)>=strlen(h))
			f=h;
	}
	
	s=strlen(f);
	free(f);
			
	for (i=0; i<n;++i)
		free(p[i]);
	printf("%d\n", s);
	return 0;
}