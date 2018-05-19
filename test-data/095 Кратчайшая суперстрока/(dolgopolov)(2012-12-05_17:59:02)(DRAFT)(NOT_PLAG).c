# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>

struct hrenq{
        char s[100];
	int i;
};


void Dijkstr(struct hrenq *p, int n, struct hrenq tmp, struct hrenq *T){
	int i, j, k, min=0, raz, flag;
	while (1){
		for (i=0; i<n; i++)	printf("%s  ", p[i].s);
		printf("\n");
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

}


int main(){
	int n, i;
	struct hrenq *p, *T;

	scanf ("%d", &n);
	p=(struct hrenq*)malloc(n*sizeof(struct hrenq));
	T=(struct hrenq*)malloc(n*sizeof(struct hrenq));
	for (i=0; i<n; i++){
		scanf("%s", &p[i].s);
		p[i].i=i;
	}
	
	Dijkstr(p, n, T[0], T);



	return 0;
}



