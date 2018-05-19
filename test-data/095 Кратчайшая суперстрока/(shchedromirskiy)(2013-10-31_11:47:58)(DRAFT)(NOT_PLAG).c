#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
        int n, j, i;
        scanf("%d", &n);
        char **s = malloc(n*sizeof *s);
	for (i=0;i<n;i++) {
		s[i] = malloc(256);
		scanf("%s",s[i]);
	}
	char *superconcat(char *s22, char *s11){
		if (s22=='\0') return s11;
		char *s2, *s1;
		int h, i, j;
		s1=malloc(256);
		s2=malloc(256);
		*s1='\0';
		strncat(s1, s11, 256);
		*s2='\0';
		strncat(s2, s22, 256);
		int len1=strlen(s11);
		int len2=strlen(s22);
		int k=256;
		int p;
		for (i=0;i<len2;i++) {
			if (s1[0]==s2[i]) {
				p=2;
				for (j=i+1,h=1;j<len2;j++,h++) {
					if (s1[h]!=s2[j]) p=0;
				}
				if (p&&(k>i)) k=i;
			}
		}
		if (k) {
			for (j=k;j<strlen(s22);j++) s2[j]=0;
			strncat(s2,s1,256);
			return s2;
		}
		strncat(s2,s1,256);
		free(s1);
		return s2;
	}
	int len=256, h[n];
	char *u;
	int comb(int *q, int m, char *sss) { /*~Super-Short-String~*/
		int j, i;
		if (m==0) {
			if (strlen(sss)<len) len = strlen(sss);
			//printf("string= %s \n", sss);
		}
		for (j=0;j<n;j++) {
			if (q[j]) {	
				q[j]=0;
				comb(q, m-1, superconcat(sss, s[j]));
				q[j]=1;
			}
		}
		return 0;
	}
	for(i=0;i<n;i++) h[i]=1;
	char *f;
	f=malloc(256);
	f='\0';
	comb(h, n, f); 
	printf("%d",len);
	u=superconcat(s[1], s[0]);
	free(u);
	for (i=0;i<n;i++) free(s[i]);
	free(s);
	return 0;
}