#include <stdio.h>
#include <stdlib.h>

char *concat(char *s1, char *s2)
{
        unsigned int j, len=1, k=0;
	char *p;
	for (j=0; (s1[j]!='\0' && s1[j]!='\n'); j++);
	len+=j;
	for (j=0; (s2[j]!='\0' && s2[j]!='\n'); j++);
	len+=j;
	p = (char*)malloc(len * sizeof(char));
	for (j=0; (s1[j]!='\0' && s1[j]!='\n'); j++)
	{
		p[k] = s1[j];
		k++;
	}
	for (j=0; (s2[j]!='\0' && s2[j]!='\n'); j++)
	{
		p[k] = s2[j];
		k++;
	}
	p[len-1] = '\0';
	return p;
}

char prefix(char *s)
{
	int i, len, t=0;
	for (i=0; (s[i]!='\0' && s[i]!='\n'); i++)
	len = i;
	int pi[len-1];
	pi[0]=0;
	for(i=1; i<len; i++)
	{
		while ((t>0) && (s[t]!=s[i]))
		{
			t = pi[t-1];
		}
		if (s[t] == s[i])
		{
			t++;
		}
		pi[i]=t;
	}
	return pi[len-1];
}

int main()
{
	char i, j, n;
	scanf("%c\n", &n);
	char *p, mas[n*n];
	char **s = (char**)malloc(n * sizeof(char*));
	printf("\n");
	for (i=0; i<n; i++)
	{
		s[i] = (char*)malloc(128 * sizeof(char));
		fgets(s[i],128,stdin);
	}
	printf("\n");
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			p = concat(s[i], s[j]);
			mas[i*n + j]=prefix(p);
			free(p);
		}
	}
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			printf("%c ", mas[i*n +j]);
		}
		printf("\n");
	}
	for (i=0; i<n; i++)
	{
		free(s[i]);
	}
	free(s);
	free(p);
	return 0;
}