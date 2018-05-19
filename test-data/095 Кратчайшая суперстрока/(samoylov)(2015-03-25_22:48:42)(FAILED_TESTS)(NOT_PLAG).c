#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void append(char *left, char *right, int max)
{
    left[strlen(left) - max] = '\0';
    strcat(left, right);
    right[0] = '\0';
}

int main()
{
    int i, j, k, n, max, left, right, res, l, m, p
    scanf("%d", &n);
    char **arr = calloc(n, sizeof(char*));
    for (i=0;i<n;i++)
    {
        arr[i] = calloc(100, sizeof(char));
        scanf("%s", arr[i]);
    }
    for (i=1;i<n;i++)
    {
        for (j=0,max=-1;j<n;j++)
            for (k=0;k<n;k++)
                if (j != k && arr[j][0] && arr[k][0])
                {
                    for (l = 1, res = p = 0; arr[j][l]; ++l, p = 0)
                    {
                        for (m = l; arr[j][m] && arr[k][p]; ++m, ++p)
                            if (arr[j][m] != arr[k][p])
                            {
                                p = 0;
                                break;
                            }
                        if (p > res)
                            res = p;
                    }
                    if (res> max)
                        max = res, left = j, right = k;
                }
        append(arr[left], arr[right], max);
        res = left;
    }
    printf("%d\n", (int) strlen(arr[res]));
    for (j = 0; j < n; ++j)
        free(arr[j]);
    free(arr);
    return 0;
}