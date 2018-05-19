#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLENGTH 32 

int glubina(char s1[STRLENGTH],char s2[STRLENGTH])
{
    int i,lbig,lmin,maxlen;
        char sbig[STRLENGTH], smin[STRLENGTH];
	if(strlen(s1) > strlen(s2))
	{
		strcpy(sbig,s1);
		strcpy(smin,s2);
	}
	else 
	{
		strcpy(sbig,s2);
		strcpy(smin,s1);
	}
	lmin = strlen(smin);
	if (strstr(sbig, smin) != NULL)return lmin;
	lbig = strlen(sbig);
	for (i = 1, maxlen = 0; i<lmin; i++)
	{
		strcpy(s1,smin);
		s1[i]=0;
		strcpy(s2, sbig + lbig - i);
		if (strcmp(s1, s2) == 0)maxlen = i;
		strcpy(s1,sbig);
		s1[i]=0;
		strcpy(s2, smin + lmin - i);
		if (strcmp(s1, s2) == 0)maxlen = i;
	}

	return maxlen;
}



int perebor(char **Z,int n, char **chain, int g) 
{
    int i,G,Gcur; 
    char s[STRLENGTH];
    if(g == n)
    {
        for(i=0,G=0;i<g-1;i++)
			G+=glubina(chain[i],chain[i+1]); 
		return G;
    }
    for(i=0,G=0;i<n;i++)
    {
        if(!strlen(Z[i]))continue;
        strcpy(s,Z[i]);
        strcpy(Z[i],"");
        strcpy(chain[g],s); 
        Gcur = perebor(Z,n,chain,g+1);
		if (Gcur > G)G = Gcur;
        strcpy(Z[i],s);
    }
	return G;
}

int main()
{
    int n, m, i, j, maxlen; 
    char s[STRLENGTH]; 
	char **Z,**chain;
    printf("Input strings count: ");
    scanf("%d", &n);
	Z = calloc(n,sizeof(char*));
	chain = calloc(n,sizeof(char*));
	m = sizeof(char);
	for(i=0,maxlen=0;i<n;i++)
    {
        printf("\nInput string %d: ",i+1);
        scanf("%s", &s);
		maxlen += strlen(s);
        Z[i] = calloc(strlen(s)+2,sizeof(char));
        strcpy(Z[i],s);
		chain[i] = calloc(3,sizeof(char));
        strcpy(chain[i],"");
    }

	printf("String length: %d", maxlen - perebor(Z, n, chain, 0));
	scanf("%d", &n);
}