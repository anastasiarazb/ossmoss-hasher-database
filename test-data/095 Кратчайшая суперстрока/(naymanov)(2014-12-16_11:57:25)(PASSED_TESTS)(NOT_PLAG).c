//superstr.c
#include <stdio.h>
#include <string.h>

int overlapf(char*, char*);

int main() {
        int n, i, j, k, maxI, maxJ,
	    minlap = 100, strslen = 0, lapslen=0, max; 
	scanf("%d ", &n);
	int overlap[n][n];
	int blockedRow[n]; 
	int blockedColomn[n];
	int maxlaps[n];
	char strs[n][100];
        
        for(i = 0; i < n; i++) 
        	blockedRow[i] = blockedColomn[i] = 0;
	
	for(i=0; i<n; i++) {
		gets(strs[i]);
		strslen += strlen(strs[i]);
	}
	
	for(i=0; i<n; i++)
		for(j=0; j<n; j++) { 
			overlap[i][j] = overlapf(strs[i], strs[j]);
			if(i == j) overlap[i][j] = 0;
		}
	for(k=0; k<n; k++) {
		maxI = maxJ = max = 0;
		for(i = 0; i<n; i++)
			for(j = 0; j<n; j++) {
				if(!blockedRow[i] && !blockedColomn[j]
				   && overlap[i][j] > max) {
					maxI = i;
					maxJ = j;
					max = overlap[i][j];					
				}
				
			}
		
		blockedRow[maxI] = 1;
		blockedColomn[maxJ] = 1;
		maxlaps[k] = max;	
	}
	
	for(i=0; i<n; i++) {
		if(maxlaps[i] < minlap) minlap = maxlaps[i];
		lapslen += maxlaps[i];
	}
	lapslen -= minlap;
	printf("%d\n", strslen - lapslen);
	return 0;
}

int overlapf(char* s1, char* s2) {
	int lap = 0;
	char *str1, *str2;
	while(*s1 != '\0') {
		str1 = s1;
		str2 = s2;
		lap = 0;
		for(; (*str1 == *str2) && (*str1 != '\0'); lap++, str1++, str2++);
		if(*str1 == '\0')
			return lap;
		s1++;
	}
}
