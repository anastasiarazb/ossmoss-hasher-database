#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
        long n, j, i;
        scanf("%ld", &n);
        char s[n+1][256];
        for (i=1;i<=n;i++) scanf("%s", s[i]);
	long smatrix[n][n];	
	long superlen(char *s2, char *s1){
		long h, i, j;
		long len1=strlen(s1);
		long len2=strlen(s2);
		if (len2==0) return len1;
		long k=256;
		long p;
		for (i=0;i<len2;i++) {
			if (s1[0]==s2[i]) {
				p=2;
				for (j=i,h=0;((j<len2)&&(h<len1));j++,h++) {
					if (s1[h]!=s2[j]) {
					p=0;
					break;
					}
				}
				if (p&&(k>i)) k=i;
			}
		}
		if (k) {
			return len1+k-len2;
		}
		return len2;
	}
	for (i=1;i<=n;i++){
		for (j=1;j<=n;j++) smatrix[i][j]=superlen(s[i],s[j]);
	}
	for (j=1;j<=n;j++) smatrix[0][j]=strlen(s[j]);
	long len=256, h[n];
	int comb(long *q, long m, long sumlen, long i) { /*~Super-Short-String~*/
		long j;
		if (m==0) {
			if (sumlen<len) len = sumlen;
		}
		for (j=1;j<=n;j++) {
			if (q[j]) {	
				q[j]=0;
				comb(q, m-1, sumlen+smatrix[i][j], j);
				q[j]=1;
			}
		}
		return 0;
	}
	for(i=1;i<=n;i++) h[i]=1;
	comb(h, n, 0, 0);
	printf("%ld",len);
	return 0;
}