#include <stdio.h>
#include <string.h>

int overlap(char *a, char *b)
{
    int count = 0, i = 0, j;
    long int z;
    z = strlen(a);
    for(j = 1; z > j; j ++ )
    {
        if(a[j] == b[i])
        {
            ++ count;
            ++ i;
        }
        else
        {
            if(count != 0)
                j -= count;
            i = count =  0;
        }
    }
    return count;
}


long int merge(int f, int y, char **a, int maxoverlap)
{
    long int z, m, i, k = 0, s = 0;
    z = strlen(a[y]);
    m = strlen(a[f]);
    for(i = z; z + m - maxoverlap > i; ++ i)
    {
        a[y][i] = a[f][maxoverlap + k];
        ++ k;
    }
    a[y][i] = 0;
    s = strlen(a[y]);
        printf("%s ", a[y]);
    for(i = 0; m > i; ++ i)
        a[f][i] = '\0';
    return s;
}


int main(int argc, char * argv[])
{
    int n, i, x = 0, f = 0, maxoverlap = 0, y = 0, count, k;
    long int z, m, s = 0;
    scanf("%d\n", &n);
    char a[n][100], *p[n];
    for(i = 0; n > i; ++ i)
    {
        fgets(a[i], 100, stdin);
        a[i][strlen(a[i]) - 1] = 0;
        p[i] = a[i];
    }
    for(i = 0; n > i; ++ i)
    {
        for(k = 0; k < n; ++ k)
        {
            for(x = 0; (n > x); ++ x)
            {
                if(x == k)
                    continue;
                z = strlen(a[x]);//1 строка, с prefiksom
                m = strlen(a[k]);//0 строка, с suffiksom
                count = overlap(a[x], a[k]);
                if(count > maxoverlap)
                {
                    maxoverlap = count;
                    f = x;
                    y = k;
                }
            }
        }
        printf("%d\n", maxoverlap);
        if (overlap(a[f], a[y]) == maxoverlap)
            s = merge(y, f, p, maxoverlap);
        if (overlap(a[y], a[f]) == maxoverlap)
            s = merge(f, y, p, maxoverlap);
        maxoverlap = count = 0;
    }
    printf("%ld", s);
    return 0;
}