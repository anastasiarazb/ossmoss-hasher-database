#include <stdio.h>

int rep() {
        
	return 0;
}

comp_rec(int sn, short *b, int *s, sa) {
	int i;
	
	for (i=0; i<n; i++)
		comp_rec()
	
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


f_rec(1) {
	f_rec(11) !!!
	f_rec(12)
	f_rec(13)
	f_rec(14)
	...
}

f_rec(12) {
	f_rec(121) !!!
	f_rec(122) !!!
	f_rec(123)
	f_rec(124)
	
}


0000.0011.1111.1111
bba (ba)bccaab (abccaab)ac (aabac)acab (acab)aab
*/
