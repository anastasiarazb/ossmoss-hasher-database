#include <stdio.h>
#include <stdlib.h>

int globResult = 0;

void prefix(char *s, int *pref, int nel)
{
    int i, t = 0;
    pref[0] = 0;
    for(i = 1; i < nel; i++){
        while (t > 0 && s[t] != s[i]){
            t = pref[t - 1];
        }
        if (s[t] == s[i]) t++;
        pref[i] = t;
    }
}

int maxOverlap(char *s1, char *s2,  int len1, int len2)
{
    int *pref = (int*)malloc(sizeof(int) * (len1 + len2 + 2));
    char *s = (char*)malloc(sizeof(char) * (len1 + len2 + 2));

    int i;
    for(i = 0; i < len2; i++){
        s[i] = s2[i];
    }
    s[len2] = '#';
    for(i = 0; i < len1; i++){
        s[len2 + i + 1] = s1[i];
    }
    s[len1 + len2 + 1] = 0;

    prefix(s, pref, len1 + len2 + 1);

    int res = pref[len1 + len2];

    free(s);
    free(pref);
    return res;
}

void allSets(int **arr, int res, int ind, int step, int n, int taken)
{
    if (step == n - 1){
        if (res > globResult) globResult = res;
        return;
    }
    int i;
    for(i = 0; i < n; i++){
        if (i != ind && (taken&(1<<i)) == 0){
            allSets(arr, res + arr[ind][i], ind + 1, step + 1, n, taken|(1<<i));
        }
    }
}

int main()
{
    int n, i;

    scanf("%d\n", &n);

    char **s = (char**)malloc(n * sizeof(char*));
    for(i = 0; i < n; i++){
        s[i] = (char*)malloc(256 * sizeof(char));
        gets(s[i]);
    }

    int lens[n], j, sumLen = 0;
    for(i = 0; i < n; i++){
        lens[i] = 0;
        for(j = 0; s[i][j] != 0; j++){
            lens[i]++;
            sumLen++;
        }
    }

    int **arr = (int**)malloc(sizeof(int*) * n);
    for (i = 0; i < n; i ++){
        arr[i] = (int*)malloc(sizeof(int) * n);
    }

    for (i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            arr[i][j] = (i == j) ? 0 : maxOverlap(s[i], s[j], lens[i], lens[j]);
        }
    }


    allSets(arr, 0, 0, 0, n, 0);
    allSets(arr, 0, 1, 0, n, 0);

    printf("%d", sumLen - globResult);

    for(i = 0; i < n; i++) free(arr[i]);
    free(arr);
    for(i = 0; i < n; i++) free(s[i]);
    free(s);
    return 0;
}
