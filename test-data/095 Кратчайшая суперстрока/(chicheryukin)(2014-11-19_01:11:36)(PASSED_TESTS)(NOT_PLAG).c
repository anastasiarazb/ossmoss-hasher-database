#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_len 1000

int fps(char *s1, char *s2)
{
        int m= strlen(s1), n= strlen(s2), i, j, fps= 0;
	int z;
	//printf("%d%d\n", m, n);
	for(i=1; (i<=m) && (i<=n); i++)
	{
		z= memcmp(s2, s1+m-i, i);
		//printf("%d:%d:%d\n", i, z, m-i);
		if (z==0)
			fps=i;
	}
	return fps;
}

int main()
{
	int k, j, i;
	scanf("%d", &k);
	typedef char el_mass[max_len];
	typedef el_mass mass[k];
	scanf("\n");
	mass s;
	//char s[max_len][n];
	//char *z;
	//printf("%d\n", n);
	for (j=0; j<k; j++)
	{
		gets(s[j]);
		//scanf("\n");
		
	}
	int k1=k;
	while(k>1)
	{
		int max_fps=0, max_j=0, max_i=0;
		for(i=0; i<k; i++)
		{
			for(j=0; j<k; j++)
			{
				if(i==j)
					continue;
				int t= fps(s[i], s[j]);
				if (t> max_fps)
				{
					max_fps= t;
					max_i=i;
					max_j=j;
				}
			}
		}
		if (max_fps==0)
		{
		  	max_i=0;
			max_j=1;
		}
		memcpy(s[max_i]+strlen(s[max_i]),s[max_j]+max_fps, strlen(s[max_j])-max_fps+1);
		if(k-1!=max_j)
		{
			memcpy(s[max_j], s[k-1], strlen(s[k-1])+1);
		}
		k--;
		  
		
	}
	/*for(i=0; i<k1; i++)
	{
		printf("%d-%s\n", strlen(s[i]), s[i]);
	}*/
	printf("%d\n", strlen(s[0]));
	return 0;
}