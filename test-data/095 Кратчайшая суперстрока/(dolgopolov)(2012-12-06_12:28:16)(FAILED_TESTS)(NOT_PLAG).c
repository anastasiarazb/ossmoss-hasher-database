# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
/*# define DEBUG*/

struct zzz{
        char s[100];
        int i;
};

int Prefix ( char *a, char *b, char *S, int *pi){
    int t, i, count=strlen(S);
        S[0]='\0';
	strcat(S, a);
	strcat(S, "$");
	strcat(S, b);
    for (i=0; i<strlen(S); i++) pi[i]=0;
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
#ifdef D
	printf ("%s\n", S);
	for (i=0; i<strlen(S); i++) printf ("%d", pi[i]);
	printf("\n");
#endif D
	return pi[i-1];
}


int Dijkstr(int n, int **matrix){

	int i, j, k, f=0, raz, min, max=0, flag, tmp, *p, *p1, X=0;
	p=(int*)malloc(n*sizeof(int));
	p1=(int*)malloc(n*sizeof(int));
	for(i=0; i<n; i++) p[i]=i;

	while (1){

#ifdef DEBUG
		printf("\n");
		for(i=0; i<n; i++) printf("%d ",p[i]);
#endif // DEBUG

		max=0;
		for(i=0;i<n-1;i++)	max+=matrix[i][p[i]];
		if(max>X) X=max;

		flag=0;
		for (i=n-2; i>=0; i--)
			if (p[i] < p[i+1]){
				flag = 1;
				break;
			}
		if (flag == 0)	break;
		raz = p[i+1];
		for (j=i+1; j<n; j++){
			if (((p[j] - p[i]) <= raz) && (p[i] < p[j]))
				min = j;
		}
		tmp=p[i];
		p[i] = p[min];
		p[min] = tmp;
		for (j=i+1; j<n; j++)	p1[j] = p[j];
		j=i+1;
		for (k = n-1; k >= i+1; k--) {
			p[j] = p1[k];
			j++;
		}
	}
	free(p);
	free(p1);
	return X;
}


int main(){
	int n, i, g, **matrix, X=0;
	struct zzz *p;
	char temp[1024];
	int pi[1024];

	scanf ("%d", &n);
	p=(struct zzz*)malloc(n*sizeof(struct zzz));
	for (i=0; i<n; i++){
		scanf("%s", &p[i].s);
		X+=strlen(p[i].s);
		p[i].i=i;
	}
	matrix=(int**)malloc(n*sizeof(int*));
	for(i=0;i<n;i++){
		matrix[i]=(int*)malloc(n*sizeof(int));
		for(g=0;g<n;g++) matrix[i][g]=0;
	}

	for(i=0;i<n;i++)
		for(g=0;g<n;g++){
			if(i==g) continue;
			matrix[i][g]=Prefix(p[i].s, p[g].s, temp, pi);
		}
#ifdef DEBUG
	printf ("\n");
	printf ("%d\n", X);
	for(i=0;i<n;i++){
		printf ("\n");
		for(g=0;g<n;g++)	printf ("%d ", matrix[i][g]);
	}

	Dijkstr(n, matrix);

#endif DEBUG

	printf ("%d\n", X-Dijkstr(n, matrix));


	free(p);
	for(i=0;i<n;i++) free(matrix[i]);
	free(matrix);
 	return 0;
}