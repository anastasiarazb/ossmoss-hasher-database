#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define LENGTH 256

typedef struct {
    char data[LENGTH];
    int len;
} string_t;

int n, min = INT_MAX;
string_t *strings;
int *table;

int overlap(string_t *a, string_t *b);

void permutations();

void permutationsRec(char *used, int *holder, int m);

int main() {
    scanf("%d\n", &n);
    strings = malloc(n * sizeof(string_t));
    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i].data);
        strings[i].len = strlen(strings[i].data);
    }
    table = malloc(n * n * sizeof(int));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            table[i * n + j] = (i == j) ? -1 : overlap(strings + i, strings + j);
        }
    }
    permutations();
    printf("%d\n", min);
    free(table);
    free(strings);
    return 0;
}

int overlap(string_t *a, string_t *b) {
    for (int i = 1; i < a->len; i++) {
        if (strncmp(a->data + i, b->data, a->len - i) == 0) {
            return a->len - i;
        }
    }
    return 0;
}

void permutations() {
    char used[n];
    int holder[n];
    memset(used, 0, n);
    permutationsRec(used, holder, 0);
}

void permutationsRec(char *used, int *holder, int m) {
    if (m == n) {
        int length = strings[holder[0]].len;
        for (int i = 1; i < n; i++) {
            length += -table[holder[i - 1] * n + holder[i]] + strings[holder[i]].len;
        }
        min = length < min ? length : min;
    } else {
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                used[i] = 1;
                holder[m] = i;
                permutationsRec(used, holder, m + 1);
                used[i] = 0;
            }
        }
    }
}