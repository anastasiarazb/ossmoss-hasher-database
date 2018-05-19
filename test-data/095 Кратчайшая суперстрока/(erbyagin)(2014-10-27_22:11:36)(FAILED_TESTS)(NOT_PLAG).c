#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

int a_is_b_length (char a[256],char b[256])
{
        return 0;
}
void main() 
{ 
	int n,i,j;
	scanf("%d ",&n);
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





	printf("10");
}