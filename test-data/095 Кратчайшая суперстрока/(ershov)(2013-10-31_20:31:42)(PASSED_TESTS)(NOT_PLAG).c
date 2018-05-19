#include <stdlib.h>
#include <stdio.h> 
#include <string.h>


int count_c(char* a,char* b)
{
        int as=strlen(a); 
	int bs=strlen(b);
	int i, j;
	i=0;
	if(as==0 || bs==0)
		return 0;
	while(i<as)
	{
		j=0;
		while(j<as-i && j<bs)
		{
			if(a[i+j]==b[j])
				j++;
			else
			{
			        break;
			}
			if(i+j==as)
				return j;
		}
		i++;
	}
	return 0;
}

int main() 
{ 
	int** m;
	int n,i,i1,j,j1,k, max,res=0,t_len=0;
	char** arr;
	scanf("%d", &n);
	arr = (char**) malloc(n*sizeof (char*));
	char tmp[80];
    gets(tmp);
	for(i=0;i<n;i++)
	{
		gets(tmp);
		arr[i]=(char*)malloc((strlen(tmp)+1)*sizeof(char));
		t_len+=strlen(tmp);
		strcpy(arr[i],tmp);
	}

	m=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		m[i]=(int*)malloc(n*sizeof(int));		
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i!=j)
				m[i][j]=count_c(arr[i],arr[j]);

			else
				m[i][j]=0;
	k=0;
	while(k<n-1)
	{
		max=0;
		i1=0;
		j1=0;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if (max<m[i][j])
				{
					max=m[i][j];
					i1=i;
					j1=j;
				}
		res+=max;
		k++;
		for(i=0;i<n;i++)
		{
			m[i][j1]=0;
			m[i1][i]=0;
		}
	}
	for(i=0;i<n;i++)
		free(arr[i]);
    free(arr);
	for(i=0;i<n;i++)
		free(m[i]);
	free(m);
	t_len=t_len-res;
	printf("%d",t_len);
	//system("pause");
	return 0; 
}