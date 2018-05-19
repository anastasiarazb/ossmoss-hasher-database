# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

int Prefix ( char *S){
        int t, i;
        int *pi=(int*)calloc(strlen(S), sizeof(int));
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
	free(pi);
	return i;
}

void Revers(int m, int n, int *P){
	int i=0, j=m, swap; 
	while (i < j){
		swap = P[i];
		P[i]=P[j];
		P[j]=swap;
		i++;
		j--; 
	}
}

void Antylex( int m, int *P, int n, int **a, int *X){
	int i, swap, max=0;;
	if (m == 0){
		for(i=0;i<n-1;i++) max+=a[P[i]][P[i+1]];
		if(max>*X) *X=max;
	}else{
		for(i=0;i<m;i++){
			Antylex(m-1, P, n, a, X);
			if(i < m){
				swap = P[i];
				P[i]=P[m];
				P[m]=swap;
				Revers(m-1, n, P); 
			}
		}
	}
}

int main(){
	int **m, n, i,j,X=0,*P,l=0;
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
			if(i==j) m[i][j];
			else{
				buf[0]=0;
				strcat(buf, a[i]);
				strcat(buf, "#");
				strcat(buf, a[j]);				
				m[i][j]=Prefix(buf);
		}
	}
	P=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++) P[i]=i;
	Antylex( n-1, P, n, m, &X);
	printf("%d",l-X);
        free(P);
	for(i=0;i<n;i++) free(m[i]);
	free(m);        
	return 0;
}  