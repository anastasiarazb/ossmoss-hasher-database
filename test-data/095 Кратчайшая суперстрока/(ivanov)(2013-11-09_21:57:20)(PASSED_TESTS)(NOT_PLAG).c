#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Find_cover(char *a, char *b)
{
    int res = 0,i = 0, temp = 0,j;
    
    while(temp < strlen(a))
    {
        if(a[temp] == b[i])
        {
            j = temp;
            while(a[j] == b[i])
            {
                res++;
                i++;
                j++;
                if(j == strlen(a))
                    return res;
            }
        }
        i = 0;
        res = 0;
        temp++;
    }
    return res;
}

int Find_max(int **m, int n)
{
    int pos_j = 0,pos_i = 0,j,i,max = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0;j < n;j++)
            if (max < m[i][j])
            {
                max = m[i][j];
                pos_i = i;
                pos_j = j;
            }
    }
    
    for(i = 0; i < n; i++)
    {
        m[i][pos_j] = 0;
        m[pos_i][i] = 0;
    }
    
    return max;
}

void Free_matrix(int **arr,int n)
{
    int i;
    for (i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
}

int main(void)
{
    char** s;
    int** arr;
    int n,i,j,max;
    int maxlen = 0;
    int k = 0,res=0;
    
    scanf("%i ",&n);
    
    s = (char**)malloc(n*sizeof(char*));
    
    for(i = 0; i < n; i++)
    {
        s[i] = (char*)malloc(256*sizeof(char));
        scanf("%s",s[i]);
        maxlen += strlen(s[i]);
    }
    
    arr=(int**)malloc(n*sizeof(int*));
    
    for(i = 0; i < n; i++)
        arr[i] = (int*)malloc(n*sizeof(int));
    
    for(i = 0;i < n; i++)
        for(j = 0; j < n; j++)
        {
            if(i != j)
                arr[i][j] = Find_cover(s[i],s[j]);
            else
                arr[i][j] = 0;
        }
    
    while(k < n-1)
    {
        max = Find_max(arr,n);
        res += max;
        k++;
    }
    maxlen -= res;
    printf("%d\n",maxlen);
    
    Free_matrix(arr,n);
    Free_matrix(s,n);
    return 0;
}

