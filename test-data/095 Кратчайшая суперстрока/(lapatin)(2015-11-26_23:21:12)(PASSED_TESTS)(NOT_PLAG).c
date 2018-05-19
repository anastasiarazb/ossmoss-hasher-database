#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(char *s1, char *s2, int overlap){
        int len = strlen(s1);
	s1[len - overlap] = '\0';
	strcat(s1,s2);
	s2[0] = '\0';
}

int overlap(char *s1, char *s2){
	int res = 0;
	int k = 0;
	for (int i = 1; s1[i]; i++){
		for (int j = i; s1[j] && s2[k]; j++, k++)
			if (s1[j] != s2[k]){
				k = 0;
				break;
			}
		if (k > res)
			res = k;
		k = 0;
	}
	return res;
}

int main(){
	int n = 0;
	scanf("%d", &n);
	char **mas = (char**) malloc (n * sizeof(char*));
	char *tmp;
	for (int i = 0; i < n; i++){
		mas[i] = (char*) malloc (100 * sizeof(char));
		scanf("%s", mas[i]);
	}
	int msi = 0;
	int msj = 0;
	int res = 0;
	for (int k = 1; k < n; k++){
		int max_overlap = -1;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (i != j && mas[i][0] && mas[j][0]){
					int current_overlap = overlap(mas[i], mas[j]);
					if (current_overlap > max_overlap){
						max_overlap = current_overlap;
						msi = i;
						msj = j;
					}	
				}
			}
		}

		merge(mas[msi], mas[msj], max_overlap);
		res = msi;
	}
	printf("%lu\n", strlen(mas[res]));
	for (int i = 0; i < n; i++) free(mas[i]);
	free(mas);
	return 0;


}
