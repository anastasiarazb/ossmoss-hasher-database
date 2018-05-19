#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **strs;
int n;
int S;
int sumStrLen;
int minSupstrLen;
int **overlapMatrix;

void permr(int x, char* perm) {
    if(x == 0) {
        int psl = permstrlen(perm);
        minSupstrLen = (minSupstrLen > psl) ? psl : minSupstrLen;
        free(perm);
        return;
    }
    if(perm == NULL) {
        perm = (char*) malloc(S);
        memset(perm, 0, S);
    }
    int i;
    for(i = 0; i < n; i++) {
        if(perm[i] == 0) {
            char *nperm = (char*) malloc(S);
            memcpy(nperm, perm, S);
            nperm[i] = x - 1;
            permr(x - 1, nperm);
        }
    }
    free(perm);
}

int overlap(char *str1, char *str2) {
    int i, j;
    for(i = 0; str1[i] != '\0'; i++) {
        for(j = 0; ; j++) {
            if(str1[i + j] == '\0' || str2[j] == '\0')
                return strlen(str1 + i);
            if(str1[i + j] != str2[j])
                break;
        }
    }
    return strlen(str1 + i);
}

int permstrlen(char *perm) {
    int i;
    int crossLen = 0;
    for(i = 0; i < n - 1; i++) {
        crossLen += overlapMatrix[perm[i]][perm[i + 1]];
    }
    return sumStrLen - crossLen;
}

int main(int argc, char **argv) {
    scanf("%d\n", &n);
    int i, j;
    strs = (char**) malloc(n * sizeof(char*));
    for(i = 0; i < n; i++) {
        strs[i] = malloc(256 * sizeof(char));
        gets(strs[i]);
        sumStrLen += strlen(strs[i]);
    }
    overlapMatrix = (int**) malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++) {
        overlapMatrix[i] = (int*) malloc(sizeof(int) *n);
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i != j) {
                overlapMatrix[i][j] = overlap(strs[i], strs[j]);
            }
        }
    }
    minSupstrLen = sumStrLen;
    S = sizeof(char) * n;
    permr(n, NULL);
    printf("%d\n", minSupstrLen);
    return 0;
}
