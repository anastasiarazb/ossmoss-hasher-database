#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Overlap(char *T, char *S)
{
    int i, k, j, res;
    for (i = 1, res = k = 0; T[i]; ++i, k = 0)
    {
        for (j = i; T[j] && S[k]; ++j, ++k)
            if (T[j] != S[k])
            {
                k = 0;
                break;
            }
        if (k > res)
            res = k;
    }
    return res;
}

void append(char *first, char *second, int overlap)
{
    first[strlen(first) - overlap] = '\0';
    strcat(first, second);
    second[0] = '\0';
}

int main()
{
    int i, j, k, n, max, left, right, res;
    scanf("%d", &n);
    char **arr = calloc(n, sizeof(char*));
    for (i=0;i<n;i++)
    {
        arr[i] = calloc(100, sizeof(char));
        scanf("%s", arr[i]);
    }
    for (i=1;i<n;i++)//i=k
    {
        for (j=0,max=-1;j<n;j++)//i=j
            for (k=0;k<n;k++)//j==k
                if (j != k && arr[j][0] && arr[k][0])
                {
                    int cur = Overlap(arr[j], arr[k]);
                    if (cur > max)
                        max = cur, left = j, right = k;
                }
        append(arr[left], arr[right], max);
        res = left;
    }
    printf("%d\n", (int) strlen(arr[res]));
    for (j = 0; j < n; ++j)
        free(arr[j]);
    free(arr)
    return 0;
}