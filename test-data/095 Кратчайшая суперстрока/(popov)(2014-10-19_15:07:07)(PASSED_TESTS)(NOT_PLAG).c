#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char **mas, int a, int b){
        char *temp = mas[a];
	mas[a] = mas[b];
	mas[b] = temp;
}

void perm(char **mas, int n, int num, int *answer){
	int i;
	if(num == n - 1){
		int q, backupI, backup, point, ans, all;
		for(all = 0, q = 1; q < n; q++){
			for(backupI = strnlen(mas[q - 1], 100), i = 1, point = 0; i < backupI; i++){
				if(mas[q - 1][i] == mas[q][point]) point++;
				else if(point){
					i -= point;
					point = 0;
				}
			}
			all += backupI - point;
		}
		all += strnlen(mas[q - 1], 100);
		if((!*answer) || (all < *answer)) *answer = all;
	} else {
		for(i = num; i < n; i++){
			swap(mas, i, num);
			perm(mas, n, num + 1, answer);
			swap(mas, i, num);
		}
	}
}
int main(int argc, char **argv)
{
	char i, n;
	scanf("%hhd ",&n);
	char m[n][100], *p[n];
	for(i = 0; i < n; i++){
		p[i] = m[i]; 
		fgets(p[i], 100, stdin); 
		p[i][strnlen(p[i], 100) - 1] = '\0';
	}
	int answer = 0;
	perm(p, n, 0, &answer);
	printf("%d\n", answer);
	return 0;
}