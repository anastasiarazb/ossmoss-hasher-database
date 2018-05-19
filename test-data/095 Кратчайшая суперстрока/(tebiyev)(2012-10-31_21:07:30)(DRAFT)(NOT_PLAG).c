#include <stdio.h>
#include <string.h>

int rep(char *p1, char *p2) {
        int l, i, c=0;
	char *s1, *s2;
	if (str/*n*/len(p1/*,50*/)>str/*n*/len(p2/*,50*/))
		l=str/*n*/len(p2/*,50*/);
	else
		l=str/*n*/len(p1/*,50*/);
	s1=malloc(l*sizeof(char));
	s2=malloc(l*sizeof(char));
	for (i=1; i<l && c==0 ; i++) {
		strncpy(s1,p1+i,50);
		strncpy(s2,p2,l-i);
		s2[l-i]=0;
		if (strcmp(s1,s2)==0)
			c=l-i;
	}
//b(abccaab) (abccaab)ac
	return c;
}

main() {
	char s1[50], s2[50];
	gets(s1);
	gets(s2);
	printf("%d\n",rep(s1,s2));
	return 0;
}
/*
void comp_rec(int sn, short *b, int *sum, int sc, int n, int *max) {
	int i;
	if (sc!=0)
		b[sc]=b[sc-1]|(1<<sn);
	for (i=0; i<n && sc<n; i++)
		if (b[sc]==b[sc]|(1<<i))
			comp_rec(i,b,sum,sc+1,n,max);
//	if sum[sc]>*max
//		*max=sum[sc];
}

int maina() {
	int n, i, *sum, *max;
	char **P;
	short *b;
	*max=0;
	scanf("%d\n",&n);
	b=malloc(n*sizeof(short));
	b[0]=(1<<10)-1;
	sum=malloc(n*sizeof(int));
	P=malloc(n*sizeof(char*));
	for (i=0; i<n; i++) {
		P[i]=malloc(50*sizeof(char));
		gets(P[i]);
	}
	
	comp_rec(0,b,sum,0,n,max);
//	
	for (i=0; i<n; i++)
		free(P[i]);
	free(P);
	return 0;
}
*/
