#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int rec (char* a, char* b) {
    int i, j, k;
    if (strlen(a) < strlen(b))
        k = strlen(a);
    else
        k = strlen(b);
    for (i = k; i > 0; i--) {
        for (j = 0; j < i && b[j] == a[strlen(a)-i+j]; j++) {
        }
        if (j==i)
            break;
     }
     return strlen(b)-i;
 }

int superstr(char **s, int nel, int maxl)
{
    int **m, i, j, i1, j1, max, res, k ;
    m = (int**)malloc(nel*sizeof(int*));
    for(i = 0; i < nel; i++)
        m[i] = (int*)malloc(nel*sizeof(int));
    for(i = 0; i < nel; i++) {
        j = 0;
        while(j < nel) {
            if(j == i)
                m[i][j] = -1;
            else
                m[i][j] = rec(s[i], s[j]);
            j++;
        }
    }
    res = 0;
    for(k = 0; k < nel-1; k++) {
        max = 0;
        i1 = 0;
        j1 = 0;
        for(i = 0; i < nel; i++)
            for(j = 0; j < nel; j++)
                if (max < m[i][j]){
                    max = m[i][j];
                    i1 = i;
                    j1 = j;
                }
                res += max;
                for(i = 0; i < nel; i++){
                    m[i][j1] = 0;
                    m[i1][i] = 0;
                }
    }
    for(i = 0; i < nel; i++)
        free(m[i]);
    free(m);
    return maxl-res;
}

int main()
{
    char **s;
    int n, i, maxl = 0;
    scanf("%d", &n);
    s = (char**)malloc(n*sizeof(char*));
    for(i = 0; i < n; i++){
        s[i] = (char*)malloc(100*sizeof(char));
        scanf("%s", s[i]);
        maxl += strlen(s[i]);
    }
    maxl = superstr(s, n, maxl);
    printf("%d", maxl);
    for(i = 0; i < n; i++)
        free(s[i]);
    free(s);
    return 0;
}


