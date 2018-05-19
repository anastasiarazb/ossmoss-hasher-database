#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sizeofstring 255

int mygets (char*);

void BuildOverlapGraph (int, char**, unsigned char**);

int GetOverlap (char**, int, int);

int Permut (int, unsigned char**, int);

int PermutRec (int, int, unsigned char**, int, int, int);

int main(void) {
    int i, n, sum = 0;
    scanf("%d ", &n);
    char **arr = (char**)malloc(n*sizeof(char*));
    unsigned char **overlap = (unsigned char**)malloc(n*sizeof(unsigned char*));
    for (i = 0; i<n; ++i) {
        arr[i] = (char*)malloc(sizeofstring*sizeof(char));
        sum += mygets(arr[i]);
        overlap[i] = (unsigned char*)malloc(n*sizeof(unsigned char));
    }
    BuildOverlapGraph (n, arr, overlap);
    for (i = 0; i<n; ++i) free (arr[i]);
    free (arr);
    printf ("%d\n", Permut (n, overlap, sum));
    for (i = 0; i<n; ++i) free (overlap[i]);
    free (overlap);
    return 0;
}

int mygets (char *__s) {
    if (fgets(__s, sizeofstring, stdin)) {
        int len = strlen(__s);
        if ((len>0)&&(__s[len-1]=='\n')) __s[len-1] = '\0';
        return len-1;
    }
    return -1;
}

void BuildOverlapGraph (int n, char **Strings, unsigned char **overlap) {
    int i, j;
    for (i = 0; i<n; ++i)
        for (j = 0; j<n; ++j)
            overlap[i][j] = GetOverlap(Strings, i, j);
}

int GetOverlap (char **Strings, int i, int j) {
    if (i==j) return 0;
    int a, x, b, leni = strlen(Strings[i]), lenj = strlen(Strings[j]), overlap;
    for (a = leni-1, b = lenj-1; (a>=0)&&(b>=0); a = leni-1, --b, overlap = 0)
        for (x = b; (x>=0)&&(a>=0); --x, ++overlap, --a)
            if (Strings[i][a]!=Strings[j][x]) break;
            else if ((x==0)||(a==0)) return ++overlap;
    return (overlap<lenj)? overlap: lenj-1;
}

int Permut (int n, unsigned char **overlap, int sum) {
    int i, minsum = sum;
    for (i = 0; i<n; ++i) minsum = PermutRec (n, (1<<n)-(1+(1<<i)), overlap, i, sum, minsum);
    return minsum;
}

int PermutRec (int n, int Q, unsigned char **overlap, int prevstep, int sum, int minsum) {
    int i;
    if (Q)
        for (i = 0; i<n; ++i)
            if ((Q>>i)&1) minsum = PermutRec (n, Q-(1<<i), overlap, i, sum-overlap[prevstep][i], (sum-overlap[prevstep][i]<minsum)? sum-overlap[prevstep][i]: minsum);
    return (sum<minsum)? sum: minsum;
}