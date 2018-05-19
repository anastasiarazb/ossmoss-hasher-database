#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char **mas, int a, int b){
        char *temp = mas[a];
	mas[a] = mas[b];
	mas[b] = temp;
}
void perm(char **mas, int n, char *mem, int max, int num, int *answer){//массив указателей, кол-во строк, динам.строка, длин дин.стр, M, указатель на ответ
	int i;
	if(num == n - 1){
		strncpy(mem, mas[0], max);
		int point, ans, backup, q;
		for(q = 1; q < n; q++){
			for(i = strnlen(mas[q], 100) - 1, backup = point = strnlen(mem, max) - 1, ans = 0; i >= 0; i--){
				if(i <= point){
					if(mas[q][i] == mem[point]){
						point--;
						ans++;
					} else {
						if(point != backup){
							i++;
							point = backup;
							ans = 0;
						}
					}
				}
			}
			strncpy(mem + backup - ans + 1, mas[q], max - backup + ans - 1);
		}
		if(!*answer) *answer = strnlen(mem, max);
		else if((q = strnlen(mem, max)) < *answer) *answer = q;
	} else {
		for(i = num; i < n; i++){
			swap(mas, i, num);
			perm(mas, n, mem, max, num + 1, answer);
			swap(mas, i, num);
		}
	}
}
int main(int argc, char **argv)
{
	char i, n;
	int max = 0;
	scanf("%hhd ",&n);
	char m[n][100], *p[n];
	for(i = 0; i < n; i++){
		p[i] = m[i]; 
		fgets(p[i], 100, stdin); 
		p[i][strnlen(p[i], 100) - 1] = '\0';
		max += strnlen(p[i], 100); 
	}
	char *memory = (char*)malloc(max * sizeof(char) + 1);
	int answer = 0;
	perm(p, n, memory, max, 0, &answer);
	free(memory);
	printf("%d\n", answer);
	return 0;
}