#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **strs;
int n;
int S;
int sumStrLen;
int minSupstrLen;

void permr(int x, char* perm) {
    if(x == 0) {
        int psl = permstrlen(perm);
        minSupstrLen = (minSupstrLen > psl) ? psl : minSupstrLen;
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
    int i = 0, j = 0;
    for(i = 0; str1[i] != '\0'; i++) {
        for(j = 0; ; j++) {
            if(str1[j + i] != str2[j]) {
                if(str1[j + i] == '\0' || str2[j] == '\0') {
                    return i;
                } else {
                    break;
                }
            }
        }
    }
    return i;
}

int permstrlen(char *perm) {
    int i;
    char *supstr = (char*) malloc((sumStrLen + 1) * sizeof(char));
    memset(supstr, 0, (sumStrLen + 1) * sizeof(char));
    strcpy(supstr, strs[perm[0]]);
    for(i = 1; i < n; i++) {
        char* secondStr = strs[perm[i]];
        int overlapIndex = overlap(supstr, secondStr);
        int supl = strlen(supstr), l2 = strlen(secondStr);
        if(supl > l2)
            strncpy(supstr + overlapIndex, secondStr, l2);
        else
            strcpy(supstr + overlapIndex, secondStr);
    }
    int l = strlen(supstr);
    free(supstr);
    return l;
}

int main(int argc, char **argv) {
    scanf("%d\n", &n);
    int i;
    strs = (char**) malloc(n * sizeof(char*));
    for(i = 0; i < n; i++) {
        strs[i] = malloc(256 * sizeof(char));
        gets(strs[i]);
        sumStrLen += strlen(strs[i]);
    }
    minSupstrLen = sumStrLen;
    S = sizeof(char) * n;
    permr(n, NULL);
    printf("%d\n", minSupstrLen);
    return 0;
}
