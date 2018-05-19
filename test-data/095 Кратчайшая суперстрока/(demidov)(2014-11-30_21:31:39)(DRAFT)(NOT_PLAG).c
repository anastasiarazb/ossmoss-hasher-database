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
    int alen = 0;
    alen = strlen(s1);
    int len=0;
    int i=0;
    int blen = 0;
    blen = strnlen(s2,1000);
    if (alen < blen)
        len = alen;
    else if (alen > blen)
        len = blen;
    else 
        len = alen;
    int ah = 0;
    int bh = 0;
    int t = 1;
    int ret = 0;
    for (i = 0; i < len; i++)
    {
        ah = (ah + (s1[alen - 1 - i] - 'A') * t) % MOD;
        bh = ((B * bh) % MOD + (s2[i] - 'A')) % MOD;

        t = (t * B) % MOD;
 
        if (ah == bh)
            ret = i + 1;
    }

    return ret;

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
    printf("%d", result);
    for(i=0;i<n;i++)
    free(mas[i]);
    free(mas);
    return 0;
} 