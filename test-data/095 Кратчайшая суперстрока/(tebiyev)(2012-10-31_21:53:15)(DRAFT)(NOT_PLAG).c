#include <stdio.h>
#include <string.h>

int rep(char *p1, char *p2){
        int l, i, c=0;
	char *s1, *s2;
	if (strlen(p1/*,50*/)>strlen(p2/*,50*/))////
		l=strlen(p2/*,50*/);//
	else
		l=strlen(p1/*,50*/);//
	s1=malloc(l*sizeof(char));
	s2=malloc(l*sizeof(char));
	for (i=1; i<l && c==0 ; i++){
		strncpy(s1,p1+strlen(p1/*,50*/)-l+i,50);//
		strncpy(s2,p2,l-i);
		s2[l-i]=0;
		if (strcmp(s1,s2)==0)
			c=l-i;
	}
	return c;
}

void comp_rec(int sn, int sc, int n, short *b, int *sum, int *max, char **P){
	int i;
	if (sc!=-1)
		b[sc+1]=b[sc]|(1<<sn);
	for (i=0; i<n && sc<n; i++)
		if (b[sc+1]==b[sc+1]|(1<<i)){
			if (sc>0)
				sum[sc]=sum[sc-1]+rep(/*???*/,P[i]);
			comp_rec(i,sc+1,n,b,sum,max,P);
		}
			
	if sum[sc]>*max
		*max=sum[sc];
}

int main(){
	int n, i, *sum, *max;
	char **P;
	short *b;
	*max=0;
	scanf("%d\n",&n);
	b=malloc(n*sizeof(short));
	b[0]=(1<<10)-1;
	sum=malloc(n*sizeof(int));
	sum[0]=0;
	P=malloc(n*sizeof(char*));
	for (i=0; i<n; i++) {
		P[i]=malloc(50*sizeof(char));
		gets(P[i]);
	}
	comp_rec(-1,-1,n,b,sum,max,P);
	max*=-1;
	for (i=0; i<n; i++)
		max+=strlen(P[i]/*,50*/)//
	printf("%d\n",max);
	for (i=0; i<n; i++)
		free(P[i]);
	free(P);
	return 0;
}
