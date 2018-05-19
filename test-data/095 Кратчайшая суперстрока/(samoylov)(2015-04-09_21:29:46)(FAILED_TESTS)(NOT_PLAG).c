#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void append(char *left, char *right, int max)
{
    left[strlen(left) - max] = '\0';
    strcat(left, right);
    right[0] = '\0';
}

void sortstr(char **arr, int n)
{
    int i, j, k;
    char *c=calloc(100, sizeof(char));
    for(i=0;i<n;i++)
    {
        j=0;
        while((j<i)&&(strlen(arr[i])>strlen(arr[j])))
            j++;
        strcpy(c, arr[i]);
        for(k=i;k>j;k--)
            strcpy(arr[k], arr[k-1]);
        strcpy(arr[j], c);
    }
    
}

/*void sstr(char **arr, int n)
{
    int i, max, j, l, res, p, k, m, left, right;
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

}*/

int main()
{
    int i, j, k, n, max, left, right, res, l, m, p, d, t1, t2, flag, t3, tneed, thave, needlen;
    scanf("%d", &n);
    char **arr = calloc(n, sizeof(char*));
    char **rez=calloc(n, sizeof(char*));
    for (i=0;i<n;i++)
    {
        arr[i] = calloc(100, sizeof(char));
        scanf("%s", arr[i]);
    }
    sortstr(arr, n);
    //for(i=0;i<n;i++)
        //printf("%s\n", arr[i]);
    for(i=0;i<n;i++)
    {
        needlen=strlen(arr[i]);
        j=i;
        if(i==0)
            d=0;
        else
            d=1;
        while(needlen==strlen(arr[j])&&j<n&&i<n)
        {
            strcpy(rez[d++], arr[i++]);
            j++;
        }
        thave=-1;
        flag=0;
        for(k=1;k<d;k++)
        {
            t1=0;
            t2=0;
            
            while(t1<strlen(rez[0]))
            {
                tneed=-1;
                t3=t1;
                while (t2<strlen(rez[k])&&t3<strlen(rez[0]))
                {
                    if(rez[0][t3]!=rez[k][t2])
                    {
                        tneed=0;
                        break;
                    }
                    t2++;
                    t3++;
                    tneed++;
                }
                
                if(tneed>thave)
                {
                    thave=tneed;
                    flag=k;
                }
                t1++;
            }
            
                       
        }
        append(rez[0], rez[flag], thave);
    }
    
        printf("%d\n", (int) strlen(rez[0]));
    for (j = 0; j < n; ++j)
    {
        free(arr[j]);
        free(rez[j]);
    }
    free(arr);
    free(rez);
    return 0;
}