#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#define MIN(a,b) (((a)<(b))?(a):(b))

int n;
char str[10][101];
int lenstr[10];
int cost[10][10];

int overlap(int i, int j) {
    int sz, k;
    for (sz = MIN(lenstr[i], lenstr[j]) ; sz > 0; sz--) {
        for (k = 0; k < sz; k++) {
            if (str[i][lenstr[i] - sz + k] != str[j][k]) {
                break;
            }
        }
        if (k == sz) {
            return sz;
        }
    }
    return 0;
}

int minlen = INT_MAX;
int permutation[10];
int exclude[10];

void solve(int pos, int len) 
{
    int i;
    if (len > minlen)
    {
        return;
    }
    if (pos == n) 
    {
        minlen = len;
    }
    for (i = 0; i < n; i++) 
    {
        if (!exclude[i]) 
        {
            exclude[i] = 1;
            permutation[pos] = i;
            if (pos == 0)
            {
                solve(pos + 1, lenstr[i]);
            } 
            else 
            {
                solve(pos + 1, len + cost[permutation[pos - 1]][permutation[pos]]);
            }
            exclude[i] = 0;
        }
    }
}

int main() 
{
    int i, j;

    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {
        scanf("%s", &str[i]);
        lenstr[i] = strlen(str[i]);
    }

    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            cost[i][j] = lenstr[j] - overlap(i, j);
        }
    }
    
    solve(0, 0);
    printf("%d\n", minlen);

    return 0;
}