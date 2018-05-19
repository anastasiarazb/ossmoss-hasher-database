
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *data [10];
int matrix [10] [10] = { 0 };
int n;

void prefix (char *s, int *p)
{
        int t, i = 1, len = strlen(s);
        p = (int *)malloc(len*sizeof(int));
        p[0] = t = 0;
        for (; i < len; i++) {
                while (t && (s[t] != s [i])) t = p[t - 1];
                if (s[t] == s[i]) t++;
                p[i] = t;
        }
} 

int Prefix (char *s, char *t, int *p)
{
        int q = 0, k = 0, len = strlen(t);
        for (; k < len; k++) {
                while (q && s[q] != t[k]) q = p[q - 1];
                if (s[q] == t[k]) q++;
        }
        return q;
}

void del (int a, int b)
{
        int i = a, j = b;
        for (; i < n; i++) for (; j < n; j++) matrix [i][j] = -1;
}

int Max ()
{
        int i = 0, j = 0, max = -1, maxi, maxj;
        for (; i < n; i++) for (; j < n; j++) if (matrix[i][j] > max) {
                max = matrix[i][j];
                maxi = i;
                maxj = j;
        }
        del (i, 0);
        del (0, j);
}

int SuperString (int len)
{
        int i = 0, j = 0, k = 0, *p;
        for (; i < n; i++) {
                prefix (data[i], p);
                for (; j < n; j++) {
                        if (i == j) continue;
                        matrix [i] [j] = Prefix (data[i], data[j], p);
                }
                free (p);
        }
        for (i = 0; i < n; i++) k += Max (n);
        return len - k;
}

int main()
{
        scanf("%d", &n);
        int i = 0, len = 0;
        //char s[1000];
        for (; i < n; i++){
                data[i] = (char *)malloc(1000*sizeof(char));
                scanf("%s", data[i]);
                len += strlen(data[i]);
                //InsertSort
        }
        printf("%d\n", SuperString(len));
        return 0;
}
