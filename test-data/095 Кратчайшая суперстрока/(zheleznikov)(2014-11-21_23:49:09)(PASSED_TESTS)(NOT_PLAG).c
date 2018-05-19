#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned long overlap(char *a, char *b)
{
    int i = 0, j = 0, answer = 0;
    long int s1len = strlen(a);
    for(i=1; s1len > i; i++ )
    {
        if(a[i] == b[j])
        {
            j++;
            answer++;
        }
        else
        {
            if(answer != 0)
            {
                i -= answer;
            }
            j=0;
            answer=0;
        }
    }
    return answer;
}

void merge (char *s1, char *s2, unsigned long overlap) {
    unsigned long s1len, s2len ;
    int i;
    s1len = strlen(s1);
    s2len = strlen(s2);
    for (i = 0; i < s2len - overlap; i++)
        s1[i + s1len] = s2[overlap + i];
}

char a[10][1000], *strtemp[100];
unsigned long  answer = 0;
int flag[10];


void super(int n, int amount)
{
    int i, j,  mi = 0, mj = 0;
    unsigned long currentoverlap = 0, maxoverlap = 0;
    if (amount == 1)
    {
        for(i = 0; i < n; ++i)
            if(flag[i] != 0)
                answer = strlen(strtemp[i]);
    }
    else
    {
        maxoverlap = 0, mi = 0, mj = 0, currentoverlap = 0;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if((i != j)&&(flag[i] != 0) && (flag[j] != 0)  )
                {
                    currentoverlap = overlap(strtemp[i], strtemp[j]);
                    if(currentoverlap >= maxoverlap)
                    {
                        mi = i;
                        mj = j;
                        maxoverlap = currentoverlap;
                    }
                }
            }
        }
        merge(strtemp[mi], strtemp[mj], maxoverlap);
        flag[mj] = 0;
        --amount;
        super(n, amount);
    }
}
int main(int argc, const char * argv[])
{
    int i, n;
    scanf("%d\n", &n);
    for(i = 0; i < n; ++i)
    {
        flag[i] = 1;
    }
    for(i = 0; i < n; i++)
    {
        strtemp[i] = a[i];
        gets(strtemp[i]);
    }
    super(n, n);
    printf("%ld\n", answer);
    return 0;
}

