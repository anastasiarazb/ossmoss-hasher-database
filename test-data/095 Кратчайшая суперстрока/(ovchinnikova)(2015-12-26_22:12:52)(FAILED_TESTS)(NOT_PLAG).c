#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int overlap(char *A, char *B);
int N = 50, min = 500;
void swap(int *x, int *y){
    int h;
    h = *x;
    *x = *y;
    *y = h;
}
void permute(int *a, int l, int r, int *lengths, int (*overlapTable)[r]){
    int i, len, j;
    if (l == r){
        len = lengths[a[0]];
                for (j = 1; j < r; j++){
                len += -overlapTable[a[j - 1]][a[j]] + lengths[a[j]];
                }
                if (len < min) {
                 min = len;
                }
        } else {
        for (i = l; i < r; i++){
            swap((a + l), (a + i));
            permute(a, l + 1, r, lengths, overlapTable);
            swap((a + l), (a + i));
        }
    }
}
int overlap(char* a, char *b) {
    int z, i, e = 0;
    for (i = 0; a[i] != '\0'; i++) {
            z = i;
            t = 0;
        while ((a[z] != '\0') && (b[t] != '\0') && (a[z] == b[t])){
            z++;
            t++;
            if ((t > e) && (a[z] == '\0')){
                e = t;
            }
        }
    }
    return e;
}
int main() {
    int i, j, k, lengths[i];
    int overlapTable[i][i];
    char S[i][N];
    int string[i];
    scanf("%d", &i);
    for (j = 0; j < i; j++) {
        string[j] = j;
    }
    for (j = 0; j < i; j++) {
        scanf("%s", S[j]);
        lengths[j] = strlen(S[j]);
    }
    for (int j = 0; j < i; j++) {
        for (k = 0; k < i; k++) {
            if (j != k){
                overlapTable[j][k] = overlap(S[j], S[k]);
            }
        }
    }
    permute(string, 0, i, lengths, overlapTable);
    printf("%d\n", min);
    return 0;
}