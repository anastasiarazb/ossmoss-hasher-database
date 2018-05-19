#include <stdio.h>
#include <stdlib.h>

int leng(char *s)
{
    int i;
    for (i=0; (s[i]!='\0' && s[i]!='\n'); i++);
    return i;
}

int prefix(char *s1, char *s2)
{
    int i, k, len1=leng(s1), len2=leng(s2), t=0;
    int pi[len1];
    pi[0]=0;
    for(i=1; i<len1; i++)
    {
        while ((t>0) && (s1[t]!=s1[i]))
	{
	    t = pi[t-1];
	}
	if (s1[t] == s1[i])
	{
	    t++;
	}
	pi[i]=t;
	
    }
    t=0;
    for(i=0; i<len2; i++)
    {
	while ((t==len1) || ((t>0) && (s1[t]!=s2[i])))
	{
	    t = pi[t-1];
	}
	if (s1[t] == s2[i])
	{
	    t++;
	}
	k=t;
    }
    return k;
}

void uni2(int *mas, int n, int *p, int bol, int sum, int pred)
{
    int i, k, d, h;
    for (i=0; i<n; i++)
    {
	d = 1 << i;
	h = bol&d;
	if (h==0)
	{
	    k = mas[pred*n + i];
	    uni2(mas, n, p, bol|d, sum + k, i);
	}
    }
    if (*p < sum)
    {
	*p = sum;
    }
}

int uni1(int *mas, int n)
{
    int i, d, min=0, max=0;
    if (n==1)
    {
	return mas[0];
    }
    for (i=0; i<n; i++)
    {
	min += mas[i*(n+1)];
    }
    for(i=0; i<n; i++)
    {
	d = 1 << i;
	uni2(mas, n, &max, d, 0, i);
    }
    return min - max;
}

int main()
{
    int i, j, n, min;
    scanf("%i\n", &n);
    char **s = (char**)malloc(n * sizeof(char*));
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
		mas[i*n + j]=prefix(s[j], s[i]);
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