#include <stdio.h>
#include <string.h>

int rep(char *p1, char *p2){
        int l, i, c=0;
        char *s1, *s2;
	if (strnlen(p1,50)>strnlen(p2,50))
		l=strnlen(p2,50);
	else
		l=strnlen(p1,50);
	s1=malloc(l*sizeof(char));
	s2=malloc(l*sizeof(char));
	for (i=1; i<l && c==0 ; i++){
		strncpy(s1,p1+strnlen(p1,50)-l+i,50);
		strncpy(s2,p2,l-i);
		s2[l-i]=0;
		if (strcmp(s1,s2)==0)
			c=l-i;
	}
	return c;
}

void comp_rec(int sn, int sc, int n, short *b, int *sum, int *max, char **P){
	int i,j; short bb;printf("\tcomp_rec(sn=%d,sc=%d,...)\n",sn,sc);					//
	if (sc!=-1) {
		b[sc+1]=b[sc]&~(1<<sn);
		//////////////////////////////////////////////////
		for(j=0,bb=b[sc+1];j<n;j++)			//
			printf("%d",bb%2),bb/=2;		//
		printf("\n");					//
		//////////////////////////////////////////////////
		
		
		
	}
	for (i=0; i<n && sc<n; i++){
		//////////////////////////////////////////////////
		printf("b=");					//
		for(j=0,bb=b[sc+1];j<n;j++)			//
			printf("%d",bb%2),bb/=2;		//
		printf("\n  ");					//
		for(j=0,bb=1<<i;j<n;j++)			//
			printf("%d",bb%2),bb/=2;		//
		printf("\n");					//
		//////////////////////////////////////////////////
		if (b[sc+1]==(b[sc+1]|(1<<i))){
			//////////////////////////////////////////
			printf(".sc=%d, sn=%d\n",sc,sn);	//
			//////////////////////////////////////////
			if (sc>0)
				sum[sc]=sum[sc-1]+rep(P[sn],P[i]),printf("..sum[sc=%d]=%d, sum[sc-1=%d]=%d, rep(P[sn=%d],P[i=%d]=%d\n)",sc,sum[sc],sc-1,sum[sc-1],sn,i,rep(P[sn],P[i]));
			printf("i=%d, sc+1=%d",i,sc+1);//////////
			comp_rec(i,sc+1,n,b,sum,max,P);
		}
	}
	if (sum[sc]>*max)
		*max=sum[sc];
}

int main(){
	int n, i, *sum, max;
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
	comp_rec(-1,-1,n,b,sum,&max,P);
	max*=-1;
	printf("max1=%d\n",max);
	for (i=0; i<n; i++)
		max+=strnlen(P[i],50);
	printf("max=%d\n",max);
	for (i=0; i<n; i++)
		free(P[i]);
	free(P);
	free(b);
	free(sum);
	return 0;
}
