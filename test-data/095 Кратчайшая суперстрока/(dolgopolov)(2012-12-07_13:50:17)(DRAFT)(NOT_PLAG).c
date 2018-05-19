# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

struct zzz{
        char s[100];
        int i;
};

int Prefix ( char *a, char *b, char *S, int *pi){

    int t, i;
    S[0]='\0';
    strcat(S, a);
    strcat(S, "$");
        strcat(S, b);
    for (i=0; i<strlen(S); i++) pi[i]=0;
	printf("%s\n", S);
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
	for (i=0; i<strlen(S); i++) printf ("%d", pi[i]);
	printf ("\n");
	return pi[strlen(S)-1];
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
	
	printf ("\n");
	for(i=0;i<n;i++){
		for(g=0;g<n;g++)
			printf ("%d ", matrix[i][g]);
	printf ("\n");
	}

	printf ("%d\n", X-Dijkstr(n, matrix));

	free(p);
	for(i=0;i<n;i++) free(matrix[i]);
	free(matrix);
 	return 0;
}