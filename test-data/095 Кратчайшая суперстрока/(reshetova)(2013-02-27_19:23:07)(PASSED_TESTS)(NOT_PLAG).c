# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

int Prefix ( char *S, int *pi){
        int t, i, count = strlen(S);
	for (i=0; i<count; i++) pi[i]=0;
	t=0;
	i=1;
	while (i < count){
		while (t>0 && S[t] != S[i])	t=pi[t-1];
		if (S[t] == S[i])	t++;
		pi[i] = t;
		i++;
	}
	i=pi[i-1];
	return i;
}

void Alg(int n, int *X, int **a){
	int i, f, k, x, swap, *P, *C, *PR, max=0;

	P=(int*)malloc((n+5)*sizeof(int));
	C=(int*)malloc((n+5)*sizeof(int));
	PR=(int*)malloc((n+5)*sizeof(int));
	
	for(i=1;i<=n;i++){ P[i]=i; C[i]=1;PR[i]=1;}
	C[n]=0;

	for(f=1;f<n;f++)
		max+=a[P[f]-1][P[f+1]-1];
	if(max>*X) *X=max;

	i=1;
	while(i<n){
		i=1; x=0;
		while(C[i]==n-i+1){
			if(PR[i] == 0) PR[i] = 1;
			else PR[i] = 0;
			C[i]=1;
			if(PR[i]==1) x++;
			i++;
		}
		if(i<n){
			if(PR[i]) k=C[i]+x;
			else k=n-i+1-C[i]+x;
			swap = P[k];
			P[k] = P[k+1];
			P[k+1] = swap;

			max=0;
			for(f=1;f<n;f++)
				max+=a[P[f]-1][P[f+1]-1];
			if(max>*X) *X=max;

			C[i]++;
		}
	}
	free(P); free(C); free(PR);
}


int main(){
	int **m, n, i,j,X=0,l=0,pi[130];
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
	Alg( n, &X, m);
	printf("%d",l-X);
	for(i=0;i<n;i++) free(m[i]);
	free(m);
	return 0;
} 