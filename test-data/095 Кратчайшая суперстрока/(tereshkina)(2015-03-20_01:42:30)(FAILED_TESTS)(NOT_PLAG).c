#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int FindOverlap(char* src1, char* src2)
{
    int len1, len2, i, j, res,c;
    
    if (src1[0] == '\0')
        return -1;
    if (src2[0] == '\0')
        return -1;
    
    len1 = (int)strlen(src1);
    len2 = (int)strlen(src2);
    
    res = 0;
    for (i = 0; i < len1; i++)
    {
        c = 0;
        for (j = i; j < len1; j++)
        {
            if (src1[j] == '\0')
                break;
            if (src2[c] == '\0')
                break;
            
            if (src1[j] == src2[c])
            {
                c++;
            }
            else
            {
                c = 0;
                break;
            }
        }
        
        if (c > res)
            res = c;
    }
    
    
    
    return res;
}


int main()
{
    int n, i, k, j, max_overlap, overlap, index1 = 0, index2 = 0;
    char** data;
    char* result = NULL;
    
    scanf("%d", &n);
    data = (char**)malloc(n*sizeof(char*));
    
    for (i = 0; i < n; i++)
    {
        data[i] = (char*)malloc(1024*sizeof(char));
        scanf("%s", data[i]);
    }
    
    for (k = 0; k < n; k++)
    {
        max_overlap = -1;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                overlap =  FindOverlap(data[i], data[j]);
                if (overlap > max_overlap)
                {
                    max_overlap = overlap;
                    index1 = i;
                    index2 = j;
                }
            }
        }
        if (max_overlap > 0)
        {
            data[index1][strlen(data[index1]) - max_overlap] = '\0';
            strcat(data[index1], data[index2]);
            data[index2][0] = '\0';
            result = data[index1];
        }
        
    }
    
    printf("%lu\n", strlen(result));
    for (i = 0; i < n; i++)
        free(data[i]);
    
    free(data);
    return 0;
}