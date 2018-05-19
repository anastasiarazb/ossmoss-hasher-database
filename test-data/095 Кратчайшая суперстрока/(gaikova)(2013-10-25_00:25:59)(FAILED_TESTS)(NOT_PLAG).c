#include <stdio.h>
#include <stdlib.h>

int leng(char *s)
{
        int i;
	for (i=0; (s[i]!='\0' && s[i]!='\n'); i++);
	return i;
}
char *concat(char *s1, char *s2)
{
	unsigned int j, len, k=0;
	char *p;
	len = 1 + leng(s1) + leng(s2);
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

int prefix(char *s)
{
	unsigned int i, len=leng(s), t=0;
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

int uni2(int *mas, int *mes, int *bol, int nom, int n)
{
	int i, max = 0, sum;
	for(i=0; i<n; i++)
	{
		if(bol[i]==0)
		{
			mes[nom] = i;
			bol[i] = 1;
			sum = uni2(mas, mes, bol, nom + 1, n) + mas[mes[nom-1]*n + i];
			bol[i] = 0;
			if(sum>max)
			{
				max = sum;
			}
		}
	}
	return max;
}

int uni1(int *mas, int n)
{
	int mes[n], bol[n], sum, min=0, max=0, i;
	for(i=0; i<n; i++)
	{
		bol[i] = 0;
	}
	if(n==1)
	{
		return mas[0];
	}
	for(i=0; i<n; i++)
	{
		min += mas[i*n + i];		
	}
	for(i=0; i<n; i++)
	{
		mes[0] = i;
		bol[i] = 1;
		sum = uni2(mas, mes, bol, 1, n);
		bol[i] = 0;
		if(sum>max)
		{
			max = sum;
		}
	}
	return min-max;
}

int main()
{
	int i, j, n, min;
	scanf("%i\n", &n);
	char *p, **s = (char**)malloc(n * sizeof(char*));
	int mas[n*n];
	for (i=0; i<n; i++)
	{
		s[i] = (char*)malloc(128 * sizeof(char));
		fgets(s[i],128,stdin);
	}
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			if (i==j)
			{
				mas[i*n + j] = leng(s[i]);
			}
			else
			{
				p = concat(s[j], s[i]);
				mas[i*n + j]=prefix(p);
				free(p);
			}
		}
	}
	min = uni1(mas, n);
	printf("%i\n", min);
	for (i=0; i<n; i++)
	{
		free(s[i]);
	}
	free(s);
	return 0;
}