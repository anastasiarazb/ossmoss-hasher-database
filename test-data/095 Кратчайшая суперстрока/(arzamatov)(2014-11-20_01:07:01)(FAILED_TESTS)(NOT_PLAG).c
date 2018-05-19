#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int prefix(char *s,char *c)
{
    int i,k,t=0;
        k=strnlen(c,10000);
	int a[k];
	a[0]=0;
	for(i=1;i<k;i++){
		while(t>0 && s[t]!=c[i]){
			t=a[t-1];
		}
		if(s[t]==c[i]){
			t++;
		}
		a[i]=t;
	}
	return a[k-1];
}
int Permut(char **a,int n){
		int i,k[n],d,j;
		char *g[n];
		for(i=0;i<n;i++){
			char *b;
			for(j=0;j<n;j++){
				g[j]=a[j];
			}
			b=a[i];
			g[i]=g[n-1];
			g[n-1]=b;
			k[i]=Permut_rec(g,n-1,b,strnlen(b,10000));
		}
		d=k[0];
        for(i=1;i<n;i++){
			if(k[i]<d){d=k[i];}
		}
		return d;
}
int Permut_rec(char **a,int n,char *s,int c){
    int i,k[n],d,q,j;
	char *g[n];
	if(n==0){
		return c;		
	}
	else{
		for(i=n-1;i>=0;i--){
			char *b;
			for(j=0;j<n;j++){
				g[j]=a[j];
			}
			b=g[i];
			g[i]=g[n-1];
			g[n-1]=b;
			q=strnlen(b,10000);
			j=prefix(b,s);
			k[i]=Permut_rec(g,n-1,b,c+q-j);
		}
		d=k[0];
		for(i=1;i<n;i++){
			if(k[i]<d){d=k[i];}
		}
		return d;
	}
}
int main()
{
	int i,n;
	scanf("%d\n",&n);
	char *s[n];
	for(i=0;i<n;i++){
		s[i]=(char *)malloc(10000);
	}
	for(i=0;i<n;i++){
		gets(s[i]);
	}
	printf("%d",Permut(s,n));
	for(i=0;i<n;i++){
		free(s[i]);
	}
	return 0;
}