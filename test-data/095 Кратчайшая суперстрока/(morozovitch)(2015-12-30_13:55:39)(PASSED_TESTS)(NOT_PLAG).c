#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
#define MAX_LEN 10000

int overlap(char *str1, char *str2) {
        int l=0;
	char *p1, *p2;
	p1=str1; 
	p2=str2;
	while(*p1) {
		if (*p1==*p2) {
			l++;
			p2++;
		} 
		else {
			p1-=l;
			l=0;
			p2=str2;
		}
		p1++;
	}
	return l;
}

void shift(int *arr) {
	int i, tmp;
	tmp = arr[1];
	for(i=2; i<arr[0]; i++)
		arr[i-1]=arr[i];
	arr[arr[0]-1]=tmp;
}

int main() {
	int i, k, n; 
	int overlaps[MAX][MAX], allow[MAX][MAX], arr[MAX];		
	int max, maxi, maxk;
	int *p;
	int sum=0;
	char strs[MAX][MAX_LEN];
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%s", strs[i]);
	for(i=0; i<n; i++)
		for(k=0; k<n; k++) {
			if (i==k) {
				overlaps[i][k]=0;
			}
			else {
				overlaps[i][k]=overlap(strs[i], strs[k]);
			}
			allow[i][k] = 1;
		}
	p=arr;
	while (1) {
		max=-1;
		maxi=-1;
		maxk=-1;
		for(i=0; i<n; i++) {
			for(k=0; k<n; k++) {
				if (allow[i][k] && (overlaps[i][k]>max)) {
					maxi=i; 
					maxk=k; 
					max=overlaps[i][k];
				}
			}
		}
		if(max==-1) {
			break;
		}
		*p++=max;
		for(i=0; i<n; i++) {
			allow[maxi][i] = 0;
			allow[i][maxk] = 0;
		}
	}
	for(i=0; i<n-1; i++)
		sum+=strlen(strs[i])-arr[i];
	sum+=strlen(strs[n-1]);
	printf("%d\n", sum);
	return 0;
}