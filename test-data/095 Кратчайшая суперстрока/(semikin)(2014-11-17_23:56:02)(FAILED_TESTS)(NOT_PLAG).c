#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int alg(char *c, int d)
{
        int i, k, t, tmp;

 
        for (k = d - 2; (k >= 0) && (c[k] >= c[k + 1]); k--);
	
 
	if (k==-1)
		return 0;
 
	for (t = d - 1; (c[k] >= c[t]) && (t >= k + 1); t--);
	
	tmp = c[k];
	c[k] = c[t];
	c[t] = tmp;
 
	for (i = k + 1; i <= (d + k)/2; i++)
	{
		t = d + k - i;
		tmp = c[i];
		c[i] = c[t];
		c[t] = tmp;
	}
 
		
	return i;
}

int main()
{
        int n, k,i,l=0,l1,l2,z,j,sum,min;
        scanf("%d ", &n);
	char b[n];
	for (i=0; i<n; i++)
		b[i]=i;
        char **st = (char**)malloc(n * sizeof(char*));
 
        for (k = 0; k < n; k++) 
	{
                st[k] = (char*)malloc(100* sizeof(char));
                gets(st[k]);
        }

	for (i=0; i<n; i++)
		l+=strlen(st[i]);
	int a[n][n];
	
	for (i=0; i<n; i++)
		for(k=0; k<n;k++)
			a[i][k]=0;
		
	for (i=0; i<n; i++)
	{
		l1=strlen(st[i]);
		char s1[l1];
		for(k=0; k<n;k++)
		{
			if(i==k)
				a[i][k]=0;
			else
			{
				l2=strlen(st[k]);
				char s2[l2];
				for (z= l1 - 1, j=1; ((z>0)&&(j<l2)); z--, j++) 
				{
					strcpy(s1, st[i]+ z);
					strncpy(s2, st[k], j);
					s2[j] = 0;
					if (strcmp(s1, s2)==0) 
						a[i][k]=j;
				}
			}
		}
	}
	min=l;
	do
	{
		for(i=0; i<n-1; i++)
		{
			sum=0;
			for(i=0; i<n-1; i++)
				sum+=a[b[i]][b[i+1]];
		}
		if (min>l-sum)
			min=l-sum;
	}
	while (alg(b,n)!=0);
	printf("%ld\n", min);
        for (k = 0; k < n; k++) 
                free(st[k]);
        free(st);
	
	
	return 0;

}