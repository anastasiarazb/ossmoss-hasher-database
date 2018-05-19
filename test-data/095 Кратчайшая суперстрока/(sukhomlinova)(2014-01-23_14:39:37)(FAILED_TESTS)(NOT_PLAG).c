
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *data [10];
int matrix [10] [10] = { 0 };
int n;

int *prefix (char *s, int *p)
{
        int t, i = 1, len = strlen(s);
        p = (int *)malloc(len*sizeof(int));
        p[0] = t = 0;
        for (; i < len; i++) {
                while (t && (s[t] != s [i])) t = p[t - 1];
                if (s[t] == s[i]) t++;
                p[i] = t;
        }
        return p;
} 

int Prefix (char *s, char *t, int *p)
{
        
        int q = 0, k = 0, len = strlen(t);
	//printf("%s %s %d\n", s, t, len);
        for (; k < len; k++) {
	  //printf(" %d %d\n", k, q);
                while (q > 0 && s[q] != t[k]) q = p[q - 1];// printf("! %d %d\n", k, q);}
                if (s[q] == t[k]) q++;
        }
        //printf("q %d\n", q);
        return q;
}

void del (int a, int b)
{
        int i = 0;
        for (; i < n; i++) {
		matrix [a][i] = -1;
		matrix [i][b] = -1;
	}
}

int Max ()
{
        int i = 0, j, max = -1, maxi = 0, maxj = 0;
        for (; i < n; i++) for (j = 0; j < n; j++) {
	  //printf("%d %d\n", i, j);
	  if (matrix[i][j] > max) {
                max = matrix[i][j];
                maxi = i;
                maxj = j;
	  }
	}
        del (maxi, maxj);
	//printf("! %d (%d;%d)\n", max, maxi, maxj);
	return max;
}

int SuperString (int len)
{
        int i = 0, j = 0, k = 0, *p;
        for (; i < n; i++) {
	  //printf("i %d %d\n", i, n);
		p = prefix (data[i], p);
                for (j = 0; j < n; j++) {
			if (i != j) matrix [i] [j] = Prefix (data[i], data[j], p);
			//printf("i %d j %d\n", i, j);
		}
                free (p);
        }
        for (i = 0; i < n; i++) { for (j = 0; j < n; j++) printf("%d ", matrix[i][j]); printf("\n");}
        for (i = 0; i < n - 1; i++) k += Max ();
	//printf("%d %d\n", len, k);
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
