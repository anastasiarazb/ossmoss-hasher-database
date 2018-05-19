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
        while(j < l1-i && j < l2) {
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

int superstr(char **s, int n, int maxl)
{
    int **array, i, j, m, t, max, d, k, h;
    array = (int**)malloc(n*sizeof(int*));
    for(i = 0; i < n; i++)
        array[i] = (int*)malloc(n*sizeof(int));
    for(i = 0; i < n; i++) {
        j = 0;
        while(j < n) {
            if(j != i)
                array[i][j] = rec(s[i], s[j]);
            else
                array[i][j] = 0;
            j++;
        }
    }
    d = 0;
    for(k = 0; k < n-1; k++) {
        m = t = max = 0;
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++) {
                if (max < array[i][j]) {
                    max = array[i][j];
                    m = i;
                    t = j;
                }
            }
            for(i = 0; i < n; i++)
                array[m][i] = array[i][t] = 0;
            d += max;
    }
    for(i = 0; i < n; i++)
        free(array[i]);
    free(array);
    h = maxl-d;
    return h;
}

int main(void)
{
    char **s;
    int n, i, maxl = 0;
    scanf("%d", &n);
    s = (char**)malloc(n*sizeof(char*));
    for(i = 0; i < n; i++) {
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

