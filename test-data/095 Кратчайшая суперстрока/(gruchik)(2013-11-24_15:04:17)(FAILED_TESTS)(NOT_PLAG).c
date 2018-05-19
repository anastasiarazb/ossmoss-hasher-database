#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **s;

int inter(int i, int j){
        int k, d, h;
	if (strlen(s[i]) >= strlen(s[j]))
 		k = strlen(s[j]) - 2;
 	else
 		k = strlen(s[i]) - 2;
	h = 0;
	for(k = k; k>=0; k--){
		if (s[j][k] == s[i][strlen(s[i])-h-1])
			h++;
		else{
			k += h;
			h = 0;
		}
	}
	return h;
} 

int main(){
	int n, i, j, size=0 ;
	scanf("%d\n", &n);
	int a[n][n];
	s = (char**)malloc(n*sizeof(char*));
	printf("olololo \n");
	for (i = 0; i<n; i++){
		s[i] = (char*)malloc(50*sizeof(char));
		scanf("%s", s[i]);
		size += strlen(s[i]);
	}
	for(i = 0; i<n; i++){
		for(j = 0; j<n; j++){
			if (j!=i)
				a[i][j] = inter(i, j);
			else
				a[i][j] = 0;
		}
	}
	int k, d, v, u, sum = 0;
	d = -1;
	for (k = 1; k<n; k++){
		for(i = 0; i<n; i++)
			for (j = 0; j<n; j++)
				if (a[i][j] > d){
					d = a[i][j];
					v = i;
					u = j;
				}
		for (i = 0; i<n; i++){
			a[v][i] = -1;
			a[i][u] = -1;
		}
		sum += d;
		d = -1;
	}
	printf ("%d\n", size-sum);
	free(s);
	return 0;
}