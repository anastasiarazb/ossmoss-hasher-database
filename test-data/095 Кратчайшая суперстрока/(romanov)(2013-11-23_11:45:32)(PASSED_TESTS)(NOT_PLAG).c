# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>

int A[10][10] = { {0} };
char S[10][100] = { {0} };

int glue(int n, int m)
{
    int i = 0, j = 0, k = 0;
    for(;i < strlen(S[n]); ++i)
    {
        j = i;
        while(j < strlen(S[n]) && S[n][j] != S[m][0])
        {
            ++j;
        }
        i = j;
        if(S[n][j] == S[m][0])
        {
            for(k = 0; j < strlen(S[n]) && S[n][j] == S[m][k]; ++k)
            {
                ++j;
            }
            if(j == strlen(S[n]))
            {
                return strlen(S[m]) - strlen(S[n]) + i;
            }
        }
        else
        {
            return strlen(S[m]);
        }
    }
}

void super(int n)
{
    int i = 0, j = 0;
    for(; i < n; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            if(i != j)
            {
                A[i][j] = glue(i, j);
            }
        }
    }
}

int answer2(int n, int sum, int *B, int prev, int s)
{
    int i = 0, ans = 10000;
    int C[10] = {0};
    for(; i < n; ++i)
    {
        if(B[i] != 0)
        {
            B[i] = 0;
            C[i] = answer2(n, sum + A[prev][i], B, i, s - 1);
            B[i] = i + 1;
        }
    }
    if(s == 0)
    {
        return sum;
    }
    for(i = 0; i < n; ++i)
    {
        if(C[i] != 0 && C[i] < ans)
        {
            ans = C[i];
        }
    }
    return ans;
}

int answer(int n)
{
    int i = 0, ans = 10000;
    int B[10] = {0};
    int C[10] = {0};
    for(; i < n; ++i)
    {
        B[i] = i + 1;
    }
    for(i = 0; i < n; ++i)
    {
        B[i] = 0;
        C[i] = answer2(n, strlen(S[i]), B, i, n - 1);
        B[i] = i + 1;
    }
    for(i = 0; i < n; ++i)
    {
        if(C[i] < ans)
        {
            ans = C[i];
        }
    }
    return ans;
}

int main (int argc , char **argv )
{
    int i = 0, n = 0;
    scanf("%d", &n);
    for(i = -1; i < n; ++i)
    {
        gets(S[i]);
    }
    super(n);
    printf("%d", answer(n));
    return 0;
}