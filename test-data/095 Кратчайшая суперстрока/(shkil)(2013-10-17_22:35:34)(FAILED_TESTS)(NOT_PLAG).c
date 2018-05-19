#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strstra(char *aa, char *bb) { 
        char *a, *b;
        int i, j, k=0, pi, pj, kt=0;
        if (strnlen(aa,255) < strnlen(bb,255)) {
                a=aa;
                b=bb;
        } else {
                a=bb; 
                b=aa;
        }
        for (i=strnlen(a,255)-1, j=0; j<strnlen(a, 255); j++){
                if (a[i]==b[j]) 
                        for (pi=i, pj=j, k=0; pj>=0; pi--, pj--, k++) 
                                if (a[pi]!= b[pj]) {
                                        k=0;
                                        break;
                                }
                if (k>kt) kt=k;
        }
                        
  
        for (i=0, j=strnlen(b, 255)-1; j>0; j--){ 
                if (a[i]==b[j]) 
                        for (pi=i, pj=j, k=0; pj<strnlen(b,255); pi++, pj++, k++) 
                                if (a[pi]!= b[pj]) {
                                        k=0; 
                                        break;
                                }
                if (k>kt) kt=k;
        }
        return kt;
}

int main() {
        int n, k, kt, ktt, i, len, point;
        char **a;
        scanf("%d\n", &n);
        a=(char**)malloc(n*sizeof(char*));
        for (i=0, len=0;i<n;i++) { 
                a[i]=(char*)malloc(255*sizeof(char));
                gets(a[i]);
                len+=strnlen(a[i],255);  
        }
        for (point=0, ktt=0; point<n-1; point++, ktt+=kt)
                for (i=point+1, kt=0; i<n; i++) {
                        k=strstra(a[point], a[i]);
                        if (k>kt) kt=k;
                }
        for (i=0; i<n; i++) free (a[i]);
        free (a);
        printf("%d\n", len-ktt);
        return 0;
}