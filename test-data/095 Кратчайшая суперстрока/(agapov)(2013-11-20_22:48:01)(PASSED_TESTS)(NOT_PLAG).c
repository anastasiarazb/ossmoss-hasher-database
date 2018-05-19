#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int strings(char *a, char *b)
{
    int alen = strlen(a), blen = strlen(b), i, j;
    for(i=0;i<alen;i++){
        j=0;
        while(j<alen-i && j<blen){
            if(a[i+j]==b[j]) j++;
            else break;
            if(i+j==alen) return j;
        }
    }
    return 0;
}

int superstr(char **str, int nel, int fulllen)
{
    int **m, i, j;
    m = (int**)malloc(nel*sizeof(int*));
    for(i=0;i<nel;i++)
        m[i] = (int*)malloc(nel*sizeof(int));
    for(i=0;i<nel;i++)
        for(j=0;j<nel;j++){
            if(j==i) m[i][j] = -1;
            else m[i][j] = strings(str[i], str[j]);
        }
    int i1, j1, max, res = 0, k = 0;
    while(k<nel-1){
        max=0;
        i1=0;
        j1=0;
        for(i=0;i<nel;i++)
            for(j=0;j<nel;j++)
                if (max<m[i][j]){
                    max=m[i][j];
                    i1=i;
                    j1=j;
                }
                res+=max;
                k++;
                for(i=0;i<nel;i++){
                    m[i][j1]=0;
                    m[i1][i]=0;
                }
    }
    for(i=0;i<nel;i++)
        free(m[i]);
    free(m);
    return fulllen-res;
}

int main()
{
    char **str;
    int n, i, fulllen = 0;
    scanf("%d", &n);
    str = (char**)malloc(n*sizeof(char*));
    for(i=0;i<n;i++){
        str[i] = (char*)malloc(100*sizeof(char));
        scanf("%s", str[i]);
        fulllen += strlen(str[i]);
    }
    fulllen = superstr(str, n, fulllen);
    printf("%d", fulllen);
    for(i=0;i<n;i++)
        free(str[i]);
    free(str);
    return 0;
}
