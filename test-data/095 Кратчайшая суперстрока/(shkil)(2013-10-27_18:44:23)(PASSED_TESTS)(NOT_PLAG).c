#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void permut (char q[10], char m, int n, char p[10], char rez[10][10], char *otvet) {
        int i, ind1,ind2, s, temp1, temp2, temp3;
        if (!m) {
                for(i=1, s=0; i<n; i++){ 
                        ind2=p[i]; 
                        ind1=p[i-1];
                        s += rez[ind1][ind2];
                }
	        if (s>*otvet) *otvet=s;
        } else 
                for (i=0; i<n; i++) 
                        if (q[i]!=-1) {
                                temp1=p[n-m];
				temp2=q[i];
				temp3=m;
				p[n-m]=q[i]; 
                                q[i]=-1; 
                                permut (q, --m, n, p, rez, otvet);
                                p[n-m]=temp1;
				q[i]=temp2;
				m=temp3;
                        }
} 

int strstra(char *aa, char *bb) { 
        int i, j, k=0, pi, pj, kt=0, min;
        if (strnlen(aa,255) < strnlen(bb,255)) min=strnlen(aa,255); else min = strnlen(bb,255);
        for (i=strnlen(aa,255)-1, j=0; j<min-1; j++){
                if (aa[i]==bb[j]) 
                        for (pi=i, pj=j, k=0; pj>=0; pi--, pj--, k++) 
                                if (aa[pi]!=bb[pj]) {
                                        k=0;
                                        break;
				}
                if (k>kt) kt=k;
				
        }            
        return kt;
}

int main() {
        char otvet=0;
        char c[10];
        char b[10]={0};
	char rez[10][10];
        int n, i, j, len;
        char **a;
        scanf("%d\n", &n);
	for (i=0; i<n; i++)
	        for (j=0;j<n;j++)
	                rez[i][j]=0;
        a=(char**)malloc(n*sizeof(char*));
        for (i=0, len=0;i<n;i++) { 
                a[i]=(char*)malloc(255*sizeof(char));
                gets(a[i]);
                len+=strnlen(a[i],255);  
        }
        for (i=0; i<n; i++)
                for (j=0; j<n; j++)
	                if (!(i==j)) rez[i][j]=strstra(a[i], a[j]);
	for (i=0;i<n;i++){
                  c[i]=-1; 
                  b[i]=i;
        }
	permut (b, n, n, c, rez, &otvet);
	printf("%d\n", len-otvet);
        for (i=0; i<n; i++) free (a[i]);
        free (a);
        return 0;
}