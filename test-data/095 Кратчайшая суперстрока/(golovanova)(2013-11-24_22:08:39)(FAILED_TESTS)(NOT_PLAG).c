#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int rec(char *a, char *b)
{
    int l1, l2, i, j;
    l1 = strlen(a);
    l2 = strlen(b);
    i = 0;
    while (i < l1) {
        j = 0;
        while(j < l1-i && j < l2){
            if(a[i+j] == b[j])
                j++;
            else
                break;
            if(i+j == l1)
                return j;
        }
        i++;
    }
    return 0;
}

int superstr(char **s, int nel, int maxl)
{
    int **array, i, j, i1, j1, max, d, k, h;
    array = (int**)malloc(nel*sizeof(int*));
    for(i = 0; i < nel; i++)
        array[i] = (int*)malloc(nel*sizeof(int));
    for(i = 0; i < nel; i++) {
        j = 0;
        while(j < nel) {
            if(j == i)
                array[i][j] = -1;
            else
                array[i][j] = rec(s[i], s[j]);
            j++;
        }
    }
    d = 0;
    for(k = 0; k < nel-1; k++) {
        max = 0;
        i1 = j1 = 0;
        for(i = 0; i < nel; i++)
            j = 0;
            while (j < nel)
                if (max < array[i][j]){
                    max = array[i][j];
                    i1 = i;
                    j1 = j;
                }
                d += max;
                for(i = 0; i < nel; i++)
                    array[i1][i] = array[i][j1] = 0;
    }
    for(i = 0; i < nel; i++)
        free(array[i]);
    free(array);
    h = maxl-d;
    return h;
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

