#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mygets (char*);

void BuildOverlapGraph (int, char**, unsigned char**);

int GetOverlap (char**, int, int);

int Permut (int, unsigned char**, int);

int PermutRec (int, int, unsigned char**, int, int, int);

int main(void) {
    int n, minsum = 0;
    scanf("%d ", &n);
    char **arr = (char**)malloc(n*sizeof(char*));
    unsigned char **overlap = (unsigned char**)malloc(n*sizeof(unsigned char*));
    for (int i = 0; i<n; ++i) {
        arr[i] = (char*)malloc(255*sizeof(char));
        minsum += mygets(arr[i]);
        overlap[i] = (unsigned char*)malloc(n*sizeof(unsigned char));
    }
    int sum = minsum;
    BuildOverlapGraph (n, arr, overlap);
    for (int i = 0; i<n; ++i) free (arr[i]);
    free (arr);
    printf ("%d\n", Permut (n, overlap, sum));
    for (int i = 0; i<n; ++i) free (overlap[i]);
    free (overlap);
    return 0;
}

int mygets (char *__s) {
    if (fgets(__s, ((*(size_t*)(__s-sizeof(size_t)))-9), stdin)) {
        int len = strlen(__s);
        if ((len>0)&&(__s[len-1]=='\n')) __s[len-1] = '\0';
        return len-1;
    }
    return -1;
}

void BuildOverlapGraph (int n, char **Strings, unsigned char **overlap) {
    for (int i = 0; i<n; ++i)
        for (int j = 0; j<n; ++j)
            overlap[i][j] = GetOverlap(Strings, i, j);
}

int GetOverlap (char **Strings, int i, int j) {
    if (i==j) return 0;
    int leni = strlen(Strings[i]), lenj = strlen(Strings[j]), overlap;
    for (int a = leni-1, b = lenj-1; (a>=0)&&(b>=0); a = leni-1, --b, overlap = 0)
        for (int x = b; (x>=0)&&(a>=0); --x, ++overlap, --a)
            if (Strings[i][a]!=Strings[j][x]) break;
            else if ((x==0)||(a==0)) return ++overlap;
    return (overlap<lenj)? overlap: lenj-1;
}

int Permut (int n, unsigned char **overlap, int sum) {
    int minsum = sum;
    for (int i = 0; i<n; ++i) minsum = PermutRec (n, (1<<n)-(1+(1<<i)), overlap, i, sum, minsum);
    return minsum;
}

int PermutRec (int n, int Q, unsigned char **overlap, int prevstep, int sum, int minsum) {
    if (Q!=0)
        for (int i = 0; i<n; ++i)
            if ((Q>>i)&1) minsum = PermutRec (n, Q-(((Q>>i)&1)<<i), overlap, i, sum-*(*(overlap+prevstep)+i), (sum-*(*(overlap+prevstep)+i)<minsum)? sum: minsum);
    return (sum<minsum)? sum: minsum;
}