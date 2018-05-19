# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

int fact(int x){
        return !x ? 1 : x*fact(x-1);
}

struct zzz{
        char s[100];
        int i;
};

int Prefix ( char *S, int *pi ){
    int t, i, count=strlen(S);
        pi[0]=0;
    t=0;
	i=1;
	while (i < strlen(S)){
		while (t>0 && S[t] != S[i])
			t=pi[t-1];
		if (S[t] == S[i])
			t++;
		pi[i] = t;
		i++;
	}
	for (i=0; i<strlen(S); i++)
		if (S[i]=='$')
			count-=pi[i-1];
	return count;
}

int Dijkstr(struct zzz *p, int n, struct zzz tmp, struct zzz *T, char *s1, int *pi){
	int i, j, k, f=0, raz, min, X, flag, *len=(int*)malloc(fact(n)*sizeof(int));
	while (1){
		s1[0]='\0';
		for (i=0; i<n; i++){
			strcat(s1, p[i].s);
			strcat(s1, "$");
		}
		len[f++]=Prefix ( s1, pi );
		flag = 0;
		for (i=n-2; i>=0; i--)
			if (p[i].i < p[i+1].i){
				flag = 1;
				break;
			}
		if (flag == 0)	break;
		raz = p[i+1].i;
		for (j=i+1; j<n; j++){
			if (((p[j].i - p[i].i) <= raz) && (p[i].i < p[j].i))
				min = j;
		}
		tmp=p[i];
		p[i] = p[min];
		p[min] = tmp;
		for (j=i+1; j<n; j++)	T[j] = p[j];
		j=i+1;
		for (k = n-1; k >= i+1; k--) {
			p[j] = T[k];
			j++;
		}
	}
	X=len[0];
	for (i=1; i<f; i++)	if (len[i]<X) X=len[i];
	free(len);
	return X;
}


int main(){
	int n, n1, i, *pi;
	struct zzz *p, *T;
	char *s1;
	scanf ("%d", &n);
	n1=n;
	p=(struct zzz*)malloc(n*sizeof(struct zzz));
	T=(struct zzz*)malloc(n*sizeof(struct zzz));
	for (i=0; i<n; i++){
		scanf("%s", &p[i].s);
		n1+=strlen(p[i].s);
		p[i].i=i;
	}
	s1=(char*)malloc(n1*100*sizeof(char));
	pi=(int*)malloc(n1*100*sizeof(int));
	printf ("%d", Dijkstr(p, n, T[0], T, s1, pi)-n);
	free(p);
	free(T);
	free(s1);
	free(pi);
	return 0;
}