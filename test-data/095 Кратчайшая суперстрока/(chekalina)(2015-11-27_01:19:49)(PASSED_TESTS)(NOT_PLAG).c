#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

void prefix(char *string, int *pi)
{
    int t, i, nel;
    pi[0]=t=0;
    i=1;
    nel=strlen(string);
    while (i<nel)
    {
        while ((t>0) && (string[t]!=string[i]))
        {
            t=pi[t-1];
        }
        if (string[t]==string[i])
        {
            t++;
        }
        pi[i]=t;
        i++;
    }
    return;
}

int kmpmodified(char *str1, char *str2, void *pref)
{
    int nel=strlen(str1)-1;
    static int pi[255];
    int q, k;
    prefix(str1, pi);
    while (nel>0)
    {
        q=k=0;
        while (k<strlen(str2))
        {
            while ((q>0) && (str1[q]!=str2[k]))
            {
                q=pi[q-1];
            }
            if (str1[q]==str2[k])
            {
                q++;
            }
            if ((q==nel)&&(k==strlen(str2)-1))
            {
                return nel;
            }
            k++;
        }
        nel--;
    }
    return nel;
}

void stcat(char *str1, char *str2, int kmp)
{
    str1[strlen(str1)-kmp] = '\0';
    strcat(str1, str2);
    str2[0] = '\0';
}


int main()
{
    char str[10][255];
    int n, i, fin, j, a, maxl, maxr, kmp, temp;
    scanf("%d ", &n);
    for (i=0; i<n; i++) gets(str[i]);
    for (i=1; i<n; i++)
    {
        kmp=-1;
        for (j=0; j<n; j++)
        {
            for (a=n-1; a>=0; a--)
            {
                if ((j!=a) && (str[j][0]!='\0') && (str[a][0]!='\0'))
                {
                    temp=kmpmodified(str[j], str[a], prefix);
                    if (temp>=kmp)
                    {
                        kmp=temp;
                        maxl=a;
                        maxr=j;
                    }
                }
            }
        }
        stcat(str[maxl], str[maxr], kmp);
        fin=maxl;
    }
    fin=strlen(str[fin]);
    printf("%d", fin);
    return 0;
}