#include <stdio.h>
#include <string.h>

int strnlen(char *s, int k){
        return strlen(s);
}

int rep(const char *p1, const char *p2){
        int l, i, j, c=0;
	char *s1, *s2;
	if (strnlen(p1,50)>strnlen(p2,50))
		l=strnlen(p2,50);
	else
		l=strnlen(p1,50);
	s1=malloc(l*sizeof(char));
	s2=malloc(l*sizeof(char));
	for (i=1; i<l && c==0 ; i++){
		//strncpy(s1,p1+strnlen(p1,50)-l+i,50);
		for(j=0; j==0 || s1[j-1]!=0;j++){
			s1[j]=p1[j+strnlen(p1,50)-l+i];
		}
		strncpy(s2,p2,l-i);
		s2[l-i]=0;
		if (strcmp(s1,s2)==0)
			c=l-i;
	}
	free(s1);
	free(s2);
	return c;
}

void nu(int **mat, int n, int *max){
	int i, j, u, a, b, m;
	for (i=0, m=0; i<n-1; i++){
		for (j=0; j<n; j++){
			for (u=0; u<n; u++){
				if(mat[j][u]>m){
					m=mat[j][u];
					a=j;
					b=u;
				}
			}
		}	
		for (j=0; j<n; j++){
			mat[a][j]=0;
			mat[j][b]=0;
		}
		*max+=m;
		m=0;
	}
	return;
}

int main(){
	int n, i, j, max, **mat;
	char **P;
	scanf("%d\n",&n);
	P=malloc(n*sizeof(char*));
	for (i=0; i<n; i++) {
		P[i]=malloc(50*sizeof(char));
		gets(P[i]);
	}
	mat=malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		mat[i]=malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			mat[i][j]=rep(P[i],P[j]);
	}
	max=0;	
	nu(mat,n,&max);
	max*=-1;
	for (i=0; i<n; i++)
		max+=strnlen(P[i],50);
	printf("%d\n",max);
	for (i=0; i<n; i++)
		free(P[i]);
	free(P);
	for (i=0; i<n; i++)
		free(mat[i]);
	free(mat);
	return 0;
}
