#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void append(char *first, char *second, int overlap)
{
    first[strlen(first) - overlap] = '\0';
    strcat(first, second);
    second[0] = '\0';
}

int main()
{
    int n, i, j, k, max, first, second, res=0, z, y, no=0;
    scanf("%d", &n);
    char **arr = calloc(n, sizeof(char*));
    for (i = 0; i < n; ++i)
    {
        arr[i] = calloc(64, sizeof(char));
        scanf("%s", arr[i]);
    }
    for (i=1;i<n;i++)//k=i
    {
        for (j=0,max=-1;j<n;j++)//i=j
            for (j = 0; j < n; ++j)//j=k
                if (j!= k && (strlen(arr[j])>0) && (strlen(arr[k])>0))
                {
                    res=0;
                    //int cur = Overlap(arr[j], arr[k]);
                    for (z=1; arr[j][z]; z++)
                    {
                        no=0;
                        for (y=z;arr[j][y]&&arr[k][no];y++, no++)
                            if(arr[j][y]!=arr[k][no])
                            {
                                no=0;
                                break;
                            }
                        if (no>res)
                            res=k;
                    }
                    if (res>max)
                        max=res, first = j, second = k;
                }
        append(arr[first], arr[second], max);
        res = first;
    }
    printf("%d\n", (int) strlen(arr[res]));
    for (i = 0; i < n; ++i)
        free(arr[i]);
    free(arr);
    return 0;
}