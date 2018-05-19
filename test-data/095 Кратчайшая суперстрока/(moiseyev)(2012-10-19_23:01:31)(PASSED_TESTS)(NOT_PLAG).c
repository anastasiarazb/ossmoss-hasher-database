#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **strs;
int n;
int S;
int sumStrLen;
int minSupstrLen;
int **overlapMatrix;

void swap(char *v, int i, int j)
{
    int t;
    t = v[i];
    v[i] = v[j];
    v[j] = t;
}


void rotateLeft(char *v, int start, int n)
{
    char tmp = v[start];
    char i;
    for (i = start; i < n - 1; i++) {
    v[i] = v[i + 1];
    }
    v[n - 1] = tmp;
}


void permute(char *v, int start, int n)
{
    int psl = permstrlen(v);
    minSupstrLen = (minSupstrLen > psl) ? psl : minSupstrLen;
    if (start < n) {
    int i, j;
    for (i = n - 2; i >= start; i--) {
        for (j = i + 1; j < n; j++) {
            swap(v, i, j);
            permute(v, i + 1, n);
        }
        rotateLeft(v, i, n);
        }
    }
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
    char *perm = (char*) malloc(sizeof(char) * n);
    for(i = 0; i < n; i++)
      perm[i] = i;
    permute(perm, 0, n);
    free(perm);
    printf("%d\n", minSupstrLen);
    return 0;
}