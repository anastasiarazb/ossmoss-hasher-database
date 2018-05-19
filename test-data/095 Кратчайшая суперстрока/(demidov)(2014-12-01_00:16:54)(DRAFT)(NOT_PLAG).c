/*http://habrahabr.ru/post/201656/*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
const int MOD = 10000007;
const int B = 101;
 
char *string[100];
int  result = 0;
int beg[10];
 
int overlap(char *s1, char *s2)
{
        int m = strlen(s1), n= strlen(s2), i=0, j=0, overlap=0;
	int z=0;
	for(i=1; (i<=m) && (i<=n); i++)
	{
		z= memcmp(s2, s1+m-i, i);
		if (z==0)
			overlap=i;
	}
	return overlap;
}
 
void merge (char *s1, char *s2, int overlap) {
    int s1len=strlen(s1)-1, s2len=strlen(s2),i=0;
    while(i < s2len - overlap){
        s1[i + s1len+1] = s2[overlap + i];
        i++;
    }
}
 
 
void createSuperString(int n, int size)
{
    int si=0, sj=0,  msi = 0, msj = 0;
    if (size > 1)
    {
        int maxoverlap = 0;
        sj=0;
        while(sj < n)
        {
                si=0;
            while(si < n)
            {
                if((si != sj)&&(beg[si] != 0 && beg[sj] != 0))
                {
                   int curoverlap = overlap(string[si], string[sj]);
                    if(curoverlap >= maxoverlap)
                    {
                        maxoverlap = curoverlap;
                        msi = si;
                        msj = sj;
                    }
                }
                si++;
            }
            sj++;
        }
        merge(string[msi], string[msj], maxoverlap);
        size--;
        beg[msj] = 0;
        createSuperString(n, size);
    }
    else
    {
        for(si = 0; si < n; si++)
            if(beg[si] != 0)
                result = strlen(string[si]);
    }
}
int main()
{
    int i, n;
    scanf("%d\n", &n);
     for(i = 0; i < n; ++i)
        beg[i] = 1;
    char **mas=(char**)malloc(sizeof(char*)*10);
    for(i=0;i<n;i++)
        mas[i]=(char*)malloc(sizeof(char)*1000);
    for(i = 0; i < n; i++)
    {
        string[i] = mas[i];
        gets(string[i]);
    }
    createSuperString(n, n);
    printf("%d\n", result);
    return 0;
}