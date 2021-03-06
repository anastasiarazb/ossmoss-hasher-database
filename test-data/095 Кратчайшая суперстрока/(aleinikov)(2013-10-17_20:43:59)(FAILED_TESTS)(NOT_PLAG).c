#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int overlap(char *A, char *B, char *S)
{
        int j,i,kl=0,kr=0,k;
	int lB=strlen(B);
	int lA=strlen(A);
	for (j=0;j<lA;j++)
		for (i=0;i<lA-j;i++)
		if (B[i]==A[j+i]) kr++;
		else {
		      break;
		      kr=0;
		}
	for (j=0;j<lB;j++)
		for (i=0;i<lB-j;i++)
		if (A[i]==B[j+i]) kl++;
		else {
		      break;
		      kl=0;
		}
	if (kr>=kl) {
		for (j=0;j<lA;j++)
		  S[j]=A[j];
		for (j=kr;j<lB;j++)
		  S[lA-kr+j]=B[j];
		S[lA-kr+lB]='\0';
		return kr;
	}else{
		for (j=0;j<lB;j++)
		  S[j]=B[j];
		for (j=kl;j<lA;j++)
		  S[lB-kl+j]=A[j];
		S[lB-kl+lA]='\0';
		return kl;
	}
}
int greedy(char **T, int N)
{
	int i,j,buff,max=0,maxi,maxj;
	int count=N;
	char remove[256],maxrem[256];
	while (count>1){
	    max=0;
	    for (i=0;i<(N-1);i++)
		if (T[i][0]!='\0')
		  for (j=i+1;j<N;j++)
			if ((T[j][0]!='\0')&&(buff=overlap(T[i],T[j],remove))>max) {
				max=buff;
				strcpy(maxrem,remove);
				maxi=i;
				maxj=j;
			}
		strcpy(T[maxi],maxrem);
		T[maxj][0]='\0';
		count--;
	}
	return strlen(T[maxi]);
}	
int main()
{       int n,i;
	scanf("%d ", &n);
	char *T[n];
	for (i=0;i<n;i++) {
		T[i]=(char*)malloc(256);
		gets(T[i]);
	}
	printf("%d",greedy(T,n));
	for (i=0;i<n;i++) free(T[i]);
	return 0;
}
 