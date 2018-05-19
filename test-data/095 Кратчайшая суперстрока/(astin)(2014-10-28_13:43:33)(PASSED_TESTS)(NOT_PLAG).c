#include <stdio.h>
#include <stdlib.h>

char *mget(char*);
int mlen(char*);
int permut(char**, int, int, int, int);
char *dop0(char*, char*);
int fprefix(char*);
int myprefix(char*, int);

int max = 0;
int ir[10][10];

int main(int argc, char **argv) {
    int n = 0, lens = 0, no = 0;
    int i, j;
    scanf("%d\n", &n);
    char *str[n];
    char v[n][256];
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) ir[i][j] = 0;
    }
    for(i = 0; i < n; i++) {
        mget(&v[i][0]);
        str[i] = &v[i][0];
    }
    for(i = 0; i < n; i++) lens += mlen(&v[i][0]);
    for(i = 0; i < n; i++) {
        no = (1 << i);
        permut(str, no, n, i, 0);
        no = 0;
    }
    printf("%d\n", lens - max);
    return 0;
}

/* Get string in S */
char *mget(char *s) {
    char k = getchar();
    int i;
    for (i = 0; k != '\0' && k != '\n'; i++) {
        s[i] = k;
        k = getchar();
    }
    s[i] = '\0';
    return s;
}

/* Return length of S-string */
int mlen(char *s) {
    int i = 0;
    while(s[i] != '\0') i++;
    return i;
}

/* This function get all different reselects of N string */
int permut(char **str, int no, int n, int j, int sumpref) {
    if (no == ((1 << n) - 1)) {
        if ((sumpref - max) > 0) max = sumpref;
        return 0;
    }
    int i;
    for(i = 0; i < n; i++) {
        if (no & (1 << i)) continue;
        no += (1 << i); 
        if (!ir[i][j]) {
            char *re = dop0(str[i], str[j]);
            ir[i][j] = myprefix(re, mlen(str[i]));
            sumpref += ir[i][j];
            free(re);
        } else {
            sumpref += ir[i][j];
        }
        permut(str, no, n, i, sumpref);
        sumpref -= ir[i][j];
        no -= (1 << i);
    }
    return 0;
}

/* my dop0, nuuu dopisivaet */
char *dop0(char *a, char *b) {
    int i = 0, j = 0;
    char *temp = (char*)malloc(256 * sizeof(char));
    while(a[i] != '\0' && a[i] != '\n') {
        temp[i] = a[i];
        i++;
    }
    while(b[j] != '\0') {
        temp[i + j] = b[j];
        j++;
    }
    temp[i + j] = '\0';
    return temp;
}

/* original prefix function */
int fprefix(char *s) {
    int len = mlen(s); 
    int p[len], i, t;
    for(i = 0; i < len; i++) p[i] = 0;
    p[0] = t = 0;
    for(i = 1; i < len; i++) {
        while((t > 0) && s[t] != s[i]) t = p[t -1];
        if (s[t] == s[i]) t++;
        p[i] = t;
    }
    return p[i - 1];
}

/* my prefix function */
int myprefix(char *s, int l0) {
    int len = mlen(s);
    int i = l0 + 1, cou = 0, j = 0, beg = 0;
    while(i < len) {
        if ((s[i] != s[j]) && beg) {
            i -= (cou - 1);
            cou = j = 0;
            beg = 0;
            continue;
        }
        if (s[i] != s[j]) {
            cou = j = 0;
            i++;
            continue;
        }
        if (s[j] == (l0 - 2) && i < (len - 1)) {
            cou = j = 0;
            continue;
        }
        if (s[i] == s[j]) {
            cou++;
            beg = 1;
            i++;
            j++;
            continue;
        }
    }
    return cou;
}

