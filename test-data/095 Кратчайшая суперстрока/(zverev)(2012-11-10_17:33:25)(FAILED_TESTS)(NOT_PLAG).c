#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

int isBit(unsigned short a, int bit);

int Permut(int** matrix, int n);
void PermutRec(int** matrix, int n, int n_loc,
               unsigned short p, int *min, int min_loc, int prev);

int Prefix(char *s1, char *s2);


int main()
{
    int i, j, n;
    char **s;
    int **matrix;

    scanf("%d", &n);
    s = (char**) malloc (sizeof(char*) * n);
    if (s == NULL)
    {
        printf("Не удалось выделить память!");
        exit(0);
    }
    for(i = 0; i < n; i++)
    {
        s[i] = (char*) malloc (sizeof(char) * SIZE);
        if (s[i] == NULL)
        {
            printf("Не удалось выделить память!");
            exit(0);
        }
    }


    for(i = 0; i < n; i++)
        scanf("%s", s[i]);

    matrix = (int**) malloc (sizeof(int*) * n);
    if (matrix == NULL)
    {
        printf("Не удалось выделить память!");
        exit(0);
    }
    for(i = 0; i < n; i++)
    {
        matrix[i] = (int*) malloc (sizeof(int) * n);
        if (matrix[i] == NULL)
        {
            printf("Не удалось выделить память!");
            exit(0);
        }
    }

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            if (i == j)
            {
                matrix[i][i] = strlen(s[i]);
            }
            else
            matrix[i][j] = strlen(s[j]) - Prefix(s[j],s[i]);
        }

    printf("%d", Permut(matrix, n));

    for(i = 0; i < n; i++)
    {
        free(matrix[i]);
        free(s[i]);
    }
    free(matrix);
    free(s);
    return 0;
}

int Permut(int** matrix, int n)
{
    int min = 1 << 30;
    unsigned short p = 0;
    PermutRec(matrix, n, n, p,  &min, 0, 0);
    return min;
}

void PermutRec(int** matrix, int n, int n_loc,
               unsigned short p, int *min, int min_loc, int prev)
{
    int i;
    if (n_loc == 0)
    {
        if(min_loc < *min) *min = min_loc;
    }
    else if (n_loc == n)
         {
            for(i = 0; i < n; i++ )
            {
                if(!isBit(p, i))
                {
                     PermutRec(matrix, n, n_loc - 1, p | (1 << i), min, matrix[i][i], i);
                }
            }
         }
         else
            for(i = 0; i < n; i++ )
            {
                if(!isBit(p, i))
                {
                     PermutRec(matrix, n, n_loc - 1, p | (1 << i), min, min_loc + matrix[prev][i], i);
                }
            }
}

int isBit(unsigned short a, int bit)
{
    return a & (1 << bit);
}

int Prefix(char *s1, char *s2)
{
    int p[60];
    char s[60];
    int i, t;

    strcpy(s, s1);
    strcat(s, s2);
    p[0] = t = 0;
    i = 1;
    while(i < strlen(s))
    {
        while((t > 0) & (s[t] != s[i]))
            t = p[t-1];
        if (s[t] == s[i])
            t++;
        p[i] = t;
        i++;
    }

    return t;
}


