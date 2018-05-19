#include <stdio.h>
#include <string.h>

/*int strnlen(char *s, int k){
        return strlen(s);
}*/

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

void comp_rec(int sn, int sc, int n, short *b, int *sum, int *max, int **mat){
	int i,j; 
	if (sc!=-1 && sc<n-1) {
		b[sc+1]=b[sc]&~(1<<sn);
	}
	for (i=0; i<n && sc<n; i++){
		if ((sc==-1)  || (b[sc]==(b[sc]|(1<<i)))){
			if (sc>0){
				sum[sc]=sum[sc-1]+mat[sn][i];
			}
			comp_rec(i,sc+1,n,b,sum,max,mat);
		}
	}
	if (sum[n-1]>*max)
		*max=sum[n-1];
	return;
}

int main(){
	int n, i, j, *sum, max, **mat;
	char **P;
	short *b;
	max=0;
	scanf("%d\n",&n);
	b=malloc(n*sizeof(short));
	b[0]=(1<<n)-1;
	sum=malloc(n*sizeof(int));
	sum[0]=0;
	P=malloc(n*sizeof(char*));
	for (i=0; i<n; i++) {
		P[i]=malloc(50*sizeof(char));
		gets(P[i]);
	}
	
	mat=malloc(n*sizeof(int*));
	for(i=0;i<n;i++)
		mat[i]=malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			mat[i][j]=rep(P[i],P[j]);
/*	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}*/
	
	
	comp_rec(-1,-1,n,b,sum,&max,mat);
	max*=-1;
/*	printf("max1=%d\n",max);*/
	for (i=0; i<n; i++)
		max+=strnlen(P[i],50);
	printf("%d\n",max);
	for (i=0; i<n; i++)
		free(P[i]);
	free(P);
	for (i=0; i<n; i++)
		free(mat[i]);
	free(mat);
	free(b);
	free(sum);
	return 0;
}
