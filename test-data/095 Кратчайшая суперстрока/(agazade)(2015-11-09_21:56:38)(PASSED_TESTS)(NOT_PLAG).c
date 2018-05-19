
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRINGSIZE 100

int overlap(char *s1, char *s2)
{
        int i, j, k;
        for (i = 1, k = 0; s1[i]; i++, k = 0) {
                for (j = i; s1[j] && s2[k]; j++, k++)
                        if (s1[j] != s2[k]) {
                                k = 0;
                                break;
                        }
                if(k) return k;
        }
}

int main()
{
        int n, i, j, k, res, max, l, r, curovl;
        char **ss;
        scanf("%d", &n);
        ss = (char**)malloc(n * sizeof(char*));
        for(i = 0; i < n; i++) {
                ss[i] = (char*)malloc(STRINGSIZE * sizeof(char));
                scanf("%s", ss[i]);
        }
        for(k = 1; k < n; k++) {
                for(i = 0, max = 0; i < n; i++)
                        for(j = 0; j < n; j++)
                                if(i != j && ss[i][0] && ss[j][0]) {
                                        curovl = overlap(ss[i], ss[j]);
                                        if(curovl >= max) max = curovl, l = i, r = j;
                                }
                ss[l][strlen(ss[l]) - max] = '\0';
                strcat(ss[l], ss[r]);
                ss[r][0] = '\0';
                res = l;
        }
        printf("%d\n", (int)strlen(ss[res]));
        for(i = 0; i < n; i++) {
                free(ss[i]);
        }
        free(ss);
        return 0;
}