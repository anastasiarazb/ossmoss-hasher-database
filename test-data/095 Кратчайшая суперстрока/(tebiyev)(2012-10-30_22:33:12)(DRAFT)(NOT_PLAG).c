#include <stdio.h>

int rep() {
        
	return 0;
}

int main() {
	int n, i;
	char **P;
	scanf("%d\n",&n);
	P=malloc(n*sizeof(char*));
	for (i=0; i<n; i++) {
		P[i]=malloc(50*sizeof(char));
		gets(P[i]);
	}
	
	
	
	for (i=0; i<n; i++)
		free(P[i]);
	free(P);
	return 0;
}





/*
bba
acabaab
babccaab
abccaabac
aabacacab

bbabccaabacacabaab




bba (ba)bccaab (abccaab)ac (aabac)acab (acab)aab
*/
