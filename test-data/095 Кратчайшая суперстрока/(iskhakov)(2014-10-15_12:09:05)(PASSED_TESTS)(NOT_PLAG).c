#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int overlap(char *str1, char* str2) {
        int l = 0;
	char *p1 = str1, *p2 = str2;
	while(*p1) {
		if(*p1 == *p2) {
			l++;
			p2++;
		} else {
			p1 -= l;
			l = 0;
			p2 = str2;
		}
		p1++;
	}
	return l;
}

int main(void) {
	int i, k, n, overlaps[10][10], allow[10][10], arr[10];
	char strs[10][10000];
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%s", strs[i]);
	for(i = 0; i < n; i++)
		for(k = 0; k < n; k++) {
			overlaps[i][k] = (i == k) ? 0 : overlap(strs[i], strs[k]);
			allow[i][k] = 1;
		}
	int max, maxi, maxk;
	int *p = arr;
	while(1) {
		max = -1;
		maxi = -1;
		maxk = -1;
		for(i = 0; i < n; i++)
			for(k = 0; k < n; k++)
				(allow[i][k] && (overlaps[i][k] > max)) ? (maxi = i, maxk = k, max = overlaps[i][k]) : 0;
		if(max == -1) break;
		*p++ = max;
		for(i = 0; i < n; i++) {
			allow[maxi][i] = 0;
			allow[i][maxk] = 0;
		}
	}
	int sum = 0;
	for(i = 0; i < n - 1; i++)
		sum += strlen(strs[i]) - arr[i];
	sum += strlen(strs[n - 1]);
	printf("%d\n", sum);
	return 0;
}
