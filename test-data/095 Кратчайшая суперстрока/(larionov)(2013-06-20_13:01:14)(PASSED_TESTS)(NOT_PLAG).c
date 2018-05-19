#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fill (const char *str1, const char *str2)
{
        int count, i;
	count = strlen(str1);
	for (i=0; count!=0; i++)
	{
		if ( strncmp(str1+i,str2,count)==0) break;
		count--;
	}

	return count;
}

int exception (int **B, int n)
{
	int i, j, i1, j1, max=0;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
			if (B[i][j]>max) 
			{
				max=B[i][j];
				i1=i;
				j1=j;
			}
	}

	if (max!=0)
	{
		for (j=0; j<n; j++)
			B[i1][j]=0;
		for (i=0; i<n; i++)
			B[i][j1]=0;
	}

	return max;
}

int main()
{
	int n;
	scanf("%d\n",&n);
	int i,j,len=0;
	
	char **A=(char**)malloc(n*sizeof(char*));
	for (i=0; i<n; i++)
		A[i]=(char*)malloc(80);

	for (i=0; i<n; i++)
	{
		gets(A[i]);
		len+=strlen(A[i]);
	}
	int **B=(int**)malloc(n*sizeof(int*));
	for (i=0; i<n; i++)
		B[i]=(int*)malloc(n*sizeof(int));

	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{	
			if (i==j)
				B[i][j]=0;
			else B[i][j]=fill(A[i],A[j]);
		}
	}
	
	int s=0;
	for (i=0; (i<n-1); i++)
		s+=exception(B,n);
	printf("%d",len-s);

	for (i=0; i<n; i++)
	{
		free(A[i]);
		free(B[i]);
	}
	free(A);
	free(B);
	return 0;
}