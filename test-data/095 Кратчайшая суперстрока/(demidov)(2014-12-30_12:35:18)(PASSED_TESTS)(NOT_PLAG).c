/*http://habrahabr.ru/post/201656/*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int MAX_SIZE = 100;

const int MOD = 10000007;
const int B = 101;

int compare(int a, int b)
{
        if (a < b) return -1;
        else if (b < a) return 1;
        else return 0;
}

int overlap(char *s1, char *s2)
{
    int alen = 0;
    strcat(s1,"\0");
    strcat(s2,"\0");
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


int main()
{
        int size=0, si=0, sj=0, n=1, max_overlap=-1, msi=0, msj=0, result=0;
	scanf("%d", &size);
	char **arr = (char**)malloc(sizeof(char*)*size);
	while(si < size)
	{
		arr[si] = (char*)malloc(sizeof(char)*MAX_SIZE);
		scanf("%s", arr[si]);
		si++;
	}
	while(compare(n,size)==-1)
	{
		si = 0;
		max_overlap = -9999;
		while(compare(si,size)==-1){
			sj=0;
			while(compare(sj,size)==-1){
				if (si != sj && arr[si][0] && arr[sj][0])
				{
					int curoverlap = overlap(arr[si], arr[sj]);
					if (compare(curoverlap,max_overlap)==1)
					{
						max_overlap = curoverlap;
						msi = si;
						msj = sj;
					}
				}
				sj++;
			}
			si++;
		}
		arr[msi][strlen(arr[msi])-max_overlap] = '\0';
		strcat(arr[msi],arr[msj]);
		arr[msj][0] = '\0';
		result = msi;
		n++;
	}
	int len = strlen(arr[result]);
	printf("%d", len);
	si = 0;
	while(compare(si,size)==-1){
		free(arr[si]);
		si++;
	}
	free(arr);
	return 0;
} 