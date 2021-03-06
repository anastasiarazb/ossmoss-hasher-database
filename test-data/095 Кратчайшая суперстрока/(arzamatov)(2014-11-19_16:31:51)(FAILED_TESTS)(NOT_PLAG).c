#include<stdio.h>
#include<stdlib.h>
int Permut(char **a,int n){
        	char c[1];
		c[0]=-1;
        return Permut_rec(a,n,n,c,0);
}
int Permut_rec(char **a,int n,int m,char *s,int c){
    int i,k[n],d,j;
	if(m==0){
		return c;
	}
	else{
		for(i=0;i<n;i++){
			char *b;
			b=a[n-1-i];
			j=strnlen(s);
			while (j>-1){
				int q=0;
				if(s[j]!=b[q]){break;}
				q++;
				j--;
			}
			k[i]=Permut_rec(a,n-1-i,m-1,b,c+j);
		}
		d=k[0];
		for(i=1;i<n;i++){
			if(k[i]<=d){d=k[i];}
		}
		return d;
	}
}
int main()
{
	int i,n;
	scanf("%d",&n);
	char *s[n];
	for(i=0;i<=n;i++){
		s[i]=(char *)malloc(10000);
	}
	for(i=0;i<=n;i++){
		gets(s[i]);
	}
	printf("%d",Permut(s,n));
	for(i=0;i<=n;i++){
		free(s[i]);
	}
	
	return 0;
}