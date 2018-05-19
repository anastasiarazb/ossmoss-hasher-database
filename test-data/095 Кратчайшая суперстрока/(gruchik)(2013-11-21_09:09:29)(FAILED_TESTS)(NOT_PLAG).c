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
	
	for(k = k; k>0; k--){
		if (s[j][k] == s[i][strlen(s[i])-h])
			h++;
		else 
			h = 0;	
		printf("olololo");
		}
	printf("inter %d\n", h);
	return h;
} 

int main(){
	int n, i, j;
	scanf("%d\n", &n);
	int a[n][n];
	s = (char**)malloc(n*sizeof(char*));
	for (i = 0; i<n; i++){
		s[i] = (char*)malloc(50*sizeof(char));
		scanf("%s", s[i]);
	}
	for(i = 0; i<n; i++)
		for(j = 1; j<n; j++)
			if (j!=i)
				a[i][j] = inter(i, j);
			else
				a[i][j] = 0;
	free (a);
	free (s);
	return 0;
}