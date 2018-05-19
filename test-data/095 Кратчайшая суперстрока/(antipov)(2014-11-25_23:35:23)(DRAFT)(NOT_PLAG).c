#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int search_substr(int n, char *b)
{        
        	int x , p, buf, r;
		for (x = n - 2;(b[x] >= b[x + 1]) && (x >= 0);x--);
		if(x == -1)
			return 0;
		for (p = n - 1;(p >= x + 1) && (b[x] >= b[p]);p--);
		buf = b[x];
		b[x] = b[p];
		b[p] = buf;
 		for (r = x + 1;r <= (x + n) / 2;r++)
		{
			p = x + n - r;
			buf = b[r];
			b[r] = b[p];
			b[p] = buf;
		}
	return r;
}

int substr_num(int n,char *b)
{	
	int j , len, len2, h, i, k, subs, l=0, suml;
	char a[n][n];
	char **string = (char**) calloc(n,sizeof(char*));
 	for (k = 0;k < n;k++) 
	{
		string[k] = (char*) calloc(15,sizeof(char));
		gets(string[k]);
	}
	for (i = 0;i < n;i++)
	l += strlen(string[i]);
	for (i = 0;i < n;i++)
		for(k = 0;k < n;k++)
		a[i][k] = 0;
		
	for (i = 0; i < n; i++)
	{
		len = strlen(string[i]);
		char s1[len];
		for(k = 0; k < n;k++)
		{
			if(i == k)
			a[i][k] = 0;
			len2 = strlen(string[k]);
			char s2[len2];
			for (j = 1 ,h = len - 1;(len2 > j) && (h > 0);j++, h--)
			{
				strcpy(s1, string[i]+ h);
				strncpy(s2, string[k], j);
				s2[j] = 0;
				if (strcmp(s1, s2) == 0)
				a[i][k] = j;
			}
		}
	}
	subs = l;
	while(search_substr(n , b) != 0)
	{
		for(i = 0;i < n-1;i++)
		{
			suml = 0;
			for(i = 0;i < n-1;i++)
			suml += a[b[i]][b[i+1]];
		}
		if (l - suml < subs)
		subs = l-suml;
	}
	for (k = 0;k < n;k++) 
	free(string[k]);
	free(string);
	return subs;
}

int main()
{
	int n, i, k, substr;
	scanf("%d", &n);
	char b[n];
	char a[n][n];
	for (i = 0;i < n;i++)
	b[i] = i;
	substr = substr_num(n , b);
	printf("%d", substr);
	return 0;
}