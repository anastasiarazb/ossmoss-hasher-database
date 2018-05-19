#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void csort(char *src, char *dest) {        
        long len=strlen(src), i, j, k=0, n, g;
	char **s = malloc((100)* sizeof *s);
	for (i=0;i<100;i++) {
		s[i]=malloc(256);
		for (j=0;j<len;j++) s[i][j]=0;
	}
	for (i=0;i<len;i++) {
		if (src[i]) {
			j=0;
			while ((i<len)&&(src[i]!=32)) {
				s[k][j]=src[i];
				i++;
				j++;
			}
			if (j) k++;
		}
	}
	n=k;
	if (n==1) {
		for (i=0;i<100;i++) free(s[i]);	
		free(s);
		return src;
	}
	long count[n];
	for(j=0;j<n;j++) count[j]=0;
	for(j=0;j<n-1;j++) {
		i=j+1;
		while (i<n) {
			if (strlen(s[i])<strlen(s[j])) count[j]=count[j]+1+strlen(s[i]);
			else count[i]=count[i]+1+strlen(s[j]);
			i++;
		}
	}
	dest=src;
	for (j=0;j<len;j++) dest[j] =32;
	for (i=0;i<n;i++) {
		k=count[i];
		for (j=count[i],g=0;g<strlen(s[i]);j++,g++) dest[j]=s[i][0+g];
	}		
	for (i=0;i<100;i++) free(s[i]);	
	free(s);
}
int main() {
	int j;
        char *s,*p;
	s=malloc(256);
	p=malloc(256);
        gets(s);
	long len=strlen(s);
	*p='\0';
        csort(s, p);
	printf("%s", p);
	free(p);
	free(s);
	return 0;
}