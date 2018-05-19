#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int intersection(char* a, char* b)
{
    int i, j;
    for (i = 0; i < strlen(a); i++){
        j = 0;
        while ((j < strlen(a)-i)&&(j < strlen(b))) {
            if (b[j] == a[i+j])
                j++;
            else
                break;
            if (i+j == strlen(a))
                return j;
        }
    }
    return 0;
}

int main()
{
    int n, i, j, q, v, k, maxz, sum = 0, f = 0;
    char** a;

    scanf("%d", &n);

    a = (char**)malloc(n*sizeof(char*));
    for (i = 0; i < n; i++)
        a[i] = (char*)malloc(50*sizeof(char));

    for(i = 0; i < n; i++){
        scanf("%s", a[i]);
        f += strlen(a[i]);
    }

    int **m;
    m = (int**)malloc(n*sizeof(int*));
    for(i = 0; i < n; i++)
        m[i] = (int*)malloc(n*sizeof(int));

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if(i == j)
                m[i][j] = 0;
            else
                m[i][j] = intersection(a[i], a[j]);
    for (k = 0; k < n-1; k++){
        maxz = 0;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                if (m[i][j] > maxz){
                    maxz = m[i][j];
                    q = i;
                    v = j;
                }
        sum += maxz;
        for (i = 0; i < n; i++){
            m[i][v] = 0;
            m[q][i] = 0;
        }
    }
    printf("%d", f - sum);
    for (i = 0; i < n; i++)
        free(a[i]);
    free(a);
    for (i = 0; i < n; i++)
        free(m[i]);
    free(m);
    return 0;
}