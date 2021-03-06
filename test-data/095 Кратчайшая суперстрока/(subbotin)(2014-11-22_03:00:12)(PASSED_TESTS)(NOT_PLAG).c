#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void juxtaposition(char **a, int n, int *f) 
{
        int i, r = 1, s, m;
                for(i = s = m = 0; i < n - 1; ++i, r = 1, s = 0) {
                        while(a[i][r]) {
                                if(a[i][r] == a[i+1][s]) ++s, ++r;
	                        else r -= s, ++r, s=0;
	   
	      
                        }
	                m += s;
                }
      
        if(f[1] - m < f[0])  f[0] = f[1] - m;
}

void Permut_rec(char **a, int n, int j, int *f) 
{ 
        if(j == n - 1) juxtaposition(a, n, f);  
        else {
                int i; 
                for(i = j; i < n; ++i) {
	                char *p = a[i];
	                a[i] = a[j];
	                a[j] = p;
	                Permut_rec(a, n, j + 1, f);
	                p = a[i];
	                a[i] = a[j];
	                a[j] = p;
                }
        }
}

int main(int argc, int **argv)
{
        int n, i, k, r;
        scanf("%d ", &n);
        char *a[n];
        char *s = (char*)malloc(20 * n * sizeof(char));
        for(i = 0, k = 0 /**a = s*/; i < n; ++i) {
                a[i] = fgets (s + (20 * i), 20 , stdin);
	        a[i][strnlen(a[i], 20) - 1]= 0;
	        k += strnlen(a[i], 20);
        }
        int p[2];
        p[1]=p[0]=k;
        Permut_rec(a, n, 0, p);
        printf("%d\n", p[0]);
	free(s);
	return 0; 
	
}