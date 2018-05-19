/////////////////////////////
// The superstring problem //
/////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Constants */

#define MAXSTRINGLENGTH 100
#define INF 100000

/* Help functions */

unsigned int max(unsigned int a, unsigned int b) {      /* Basic maximum finding (unsigned ints) */
        if (a > b) return a;
	else return b;
}

int maxint(int a, int b) {                              /* Basic maximum finding (ints) */
	if (a > b) return a;
	else return b;
}

unsigned int power(unsigned int a, unsigned int n) {    /* Fast powering */
	if (!n) return 1;
	return (n % 2) ? a * power(a, n - 1) : power(a * a, n / 2);
}

unsigned char bit(unsigned int i, unsigned long mask) { /* i bit of mask */
	return (mask >> i) % 2;
}

unsigned int count(unsigned long mask) {                /* the number of 1-bits of mask */
	return (mask == 0) ? 0 : (mask % 2) + count(mask >> 1);
}

/* Main algorithms */

unsigned int *p_function(char *s) {                     /* The prefix-function finding */
	unsigned int i, j, n = strlen(s);
	unsigned int *res = malloc(n * sizeof(unsigned int));
	res[0] = 0;
	
	for(i = 1; i < n; i++) {
		j = res[i - 1];
		while ((j > 0) && (s[i] != s[j]))
			j = res[j - 1];
		
		res[i] = j;
		if (s[i] == s[j]) res[i]++;
	}
	
	return res;
}

unsigned int cmp(char *s1, char *s2, unsigned int *f) { /* The Knuth-Morris-Pratt's algorithm. It differs a bit from p_function */
	unsigned int i, k = 0;
	for(i = 0; i < strlen(s2); i++) {
		while ((k > 0) && (s1[k] != s2[i]))
			k = f[k - 1];
		
		if (s1[k] == s2[i]) k++;
	}
	
	return k;
}

int **hamilton(unsigned int **d, unsigned int n) {      /* Finding hamiltonian path by the dynamics in the profile */
	int **dp = (int **)malloc(power(2, n) * sizeof(unsigned long *));
	unsigned int mask, i, j;
	for(i = 0; i < power(2, n); i++) {
		dp[i] = calloc(n, sizeof(int));
		for(j = 0; j < n; j++)
			dp[i][j] = ((count(i) == 1) && (bit(j, i))) ? 0 : -INF;
	}
	
	for(mask = 0; mask < power(2, n); mask++)
		for(i = 0; i < n; i++)
			if ((count(mask) - 1) && !(bit(i, mask) - 1))
				for(j = 0; j < n; j++)
					dp[mask][i] = maxint(dp[mask][i], dp[mask ^ power(2, i)][j] + d[j][i]);
	
	return (int)dp;
}

/* Core */

int main(int argc, char **argv) {
	unsigned int n, i, j, total_length = 0;
	
	//------------input and preprocessing------------
	
	scanf("%u\n", &n);
	
	char **s = (char **)malloc(n * sizeof(unsigned long*));
	char tmp_str[MAXSTRINGLENGTH];
	unsigned int *p_array[n];      	  /* array of p-functions for all strings. Needed for preprocessing of p_matrix */
	unsigned int **p_matrix = (unsigned int **)malloc(n * sizeof(unsigned long*)); /* The first part of the problem's solution, */
	              											                       /* contains prefix-functions for all ordered pairs of strings */	
	for(i = 0; i < n; i++) {
		p_matrix[i] = malloc(n * sizeof(int));
		
		gets(tmp_str);
		total_length += strlen(tmp_str);
		
		s[i] = malloc((strlen(tmp_str) + 1) * sizeof(unsigned char));
		for(j = 0; j < strlen(tmp_str); j++) {
			s[i][j] = tmp_str[j];
		}
		s[i][strlen(tmp_str)] = '\0';
		
		p_array[i] = p_function(s[i]);
	}
	
	//------------Fill the prefix-matrix-------------
	
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if (i == j) p_matrix[i][j] = 0;
			else p_matrix[i][j] = (int)cmp(s[i], s[j], p_array[i]);
	
	free(p_array);
	for(i = 0; i < n; i++)
		free(s[i]);
	free(s);
	
	//-----------Finding answer and output-----------
	
	unsigned int **dp = hamilton(p_matrix, n);
	unsigned int ans = 0;
	for(i = 0; i < n; i++) {
		if (dp[power(2, n) - 1][i] < 0) continue;
		ans = max(ans, dp[power(2, n) - 1][i]);
		free(p_matrix[i]);
	}
	
	free(p_matrix);
	
	for(i = 0; i < power(2, n); i++)
		free(dp[i]);
	free(dp);
	
	printf("%u", total_length - ans);
	
	return 0;
}