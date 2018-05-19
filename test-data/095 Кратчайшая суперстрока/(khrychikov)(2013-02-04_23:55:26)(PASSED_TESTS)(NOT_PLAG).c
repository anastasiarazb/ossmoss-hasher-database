#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int result=-1;
int p[10][10];
int o[10];


void getLast(char *a, char *res, int n)
{
        int l; int i;
	l=strlen(a);
	for (i=0; i<n; i++)
		res[i]=a[l-n+i];
	res[n]=0;
	return;
}

int prefix(char * a, char* b)
{
	char *temp;
	int i;
	temp=(char*) malloc(128*sizeof(char));
	for (i=strlen(a); i>0; i--)
	{
		getLast(a,temp,i);
		if (strstr(b,temp)==b) break;
	}
	free(temp);
	return (strlen(a)-i);
}

void Swap(int a, int b, int *x)
{
    int t=x[a];
    x[a]=x[b];
    x[b]=t;
}

int GetLen(int *probe, int n)
{
	int result=0;
	int i;
	for (i=0; i<n-1; i++)
		result=result+ p[probe[i]][probe[i+1]];
	result=result+ o[probe[n-1]];
	return result;
}


void GenerateProbe(int n, int k, int *probe)
{
	int j, temp;
    if (k==n) 
	{
		//for (i=0; i<n; i++) printf("%d ", probe[i]);
		temp=GetLen(probe, n);
		if ((temp<result)||(result==-1)) result=temp;
		//printf("\n");
		return;
	}
    else
    { 
        for(j=k; j<n; j++)
        {
            Swap(k, j, probe);
            GenerateProbe(n, k+1, probe);
            Swap(k, j, probe);
        }
    }
}

int main()
{
	int i, j; int n;
	char* s[10];
	int probe[10];
	for (i=0; i<10; i++) 
		probe[i]=-1;
	for (i=0; i<10; i++) 
	{
		s[i]=(char*) malloc(sizeof(char)*128);
		memset(s[i],0,128);
	}
	scanf("%d", &n);
	for(i=0; i<n; i++) 
	{
		scanf("%s", s[i]); 
		o[i]=strlen(s[i]);
	}
	for(i=0; i<n; i++) 
		for (j=0; j<n; j++) 
			if (i!=j) 
				{
					p[i][j]=prefix(s[i], s[j]);
				}
			else 
				{
					p[i][j]=0;
				}
    for (i=0; i<n; i++) probe[i]=i;
	GenerateProbe(n, 0, probe);
	for (i=0;i<10;i++) free(s[i]);
	printf("%d\n", result);
	return 0;
}