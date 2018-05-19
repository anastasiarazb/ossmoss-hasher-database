# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

int Prefix ( char *S, int *pi){
        int t, i;
        for (i=0; i<strlen(S); i++) pi[i]=0;
        t=0;
        i=1;
	while (i < strlen(S)){
		while (t>0 && S[t] != S[i])	t=pi[t-1];
		if (S[t] == S[i])	t++;
		pi[i] = t;
		i++;
	}
	i=pi[i-1];
	return i;
}

void Antylex( int m, int *P, int n, int **a, int *X){
	int i, swap, max=0, i1, j1;
	if (m == 1){
		for(i=0;i<n-1;i++) max+=a[P[i]][P[i+1]];
		if(max>*X) *X=max;
	}else{
		for(i=0;i<=m;i++){
			Antylex(m-1, P, n, a, X);
			if(i < m){
				swap = P[i];
				P[i]=P[m-1];
				P[m-1]=swap;
				i1=0; j1=m-1;
				while (i1 < j1){
					swap = P[i1];
					P[i1]=P[j1];
					P[j1]=swap;
					i1++;
					j1--; 
				}

			}
		}
	}
}

int main(){
	int **m, n, i,j,X=0,*P,l=0,pi[130];
	char a[10][64], buf[128];

	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%s", a[i]);
		l+=strlen(a[i]);
	}
	
	m=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++) m[i]=(int*)calloc(n,sizeof(int));
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			if(i==j) m[i][j]=0;
			else{
				buf[0]=0;
				strcat(buf, a[i]);
				strcat(buf, "#");
				strcat(buf, a[j]);				
				m[i][j]=Prefix(buf, pi);
		}
	}
	P=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++) P[i]=i;
	Antylex( n, P, n, m, &X);
	printf("%d",l-X);
	free(P);
	for(i=0;i<n;i++) free(m[i]);
	free(m);
	return 0;
} 