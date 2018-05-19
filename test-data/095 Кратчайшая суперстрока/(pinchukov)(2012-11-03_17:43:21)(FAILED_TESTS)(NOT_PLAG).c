#include <stdio.h>
#include <string.h>

int prefix( char *s1, char *s2)
{
        int k=0, max=-1,i,j,lengths1, lengths2;
	if (strcmp(s1, s2) == 0) return 0;
	else if (strcmp(s1, s2) < 0) 
	{
		lengths1=strnlen(s1,1000);
		lengths2=strnlen(s2,1000);
		for (i=0; i<lengths2; i++)
		{
			for (j=0; j<lengths2-i; j++)	
				if (s1[lengths1-lengths2+i+j]==s2[j]) k++;
				else 
				{
					k=0;
					break;
				}
		if (k>max) max=k;
		k=0;
		}
		return max;
	}
	else 
	{
		lengths1=strnlen(s1,1000);
		for (i=0; i<lengths1; i++)
		{
			for (j=0; j<lengths1-i; j++)	
				if (s1[i+j]==s2[j]) k++;
				else 
				{
					k=0;
					break;
				}
		if (k>max) max=k;
		k=0;
		}			
		return max;	
	}
}	
					

int main()
{
	int n, i, j,k,x,y,max=-1,length=0, matrix[10][10];
	char s[10][100];
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%s", s[i]);
		length+=strnlen(s[i],1000);
	}
	for (i=0; i<n; i++)
	{		
		for (j=0; j<n; j++)
			 matrix[i][j]=prefix(s[i], s[j]);
	}
	for (i=1; i<n; i++)
	{
		for (j=0; j<n; j++)
			for (k=0; k<n; k++)
			{
				if (matrix[j][k]> max) 
				{
					max= matrix[j][k];
					x=j; y=k;
				}
			}
		for (j=0; j<n; j++)
		{
			matrix[j][j]=0;
			matrix[x][j]=0;
			matrix[j][y]=0;
		}
		length-=max;
		max=0;
	}
	printf("%d", length);
	return 0;
}