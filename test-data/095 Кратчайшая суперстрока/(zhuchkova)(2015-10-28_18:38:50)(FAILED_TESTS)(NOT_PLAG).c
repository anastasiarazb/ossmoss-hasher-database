#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void count(char str[][150], const int n);
void create(char super[], char str[][150], const int n, int counter);
char* append(char dest[], char src[], const int from);

int length = 200;
int main()
{
    int n, i;
    scanf("%d", &n);

    char str[n][150];
        for (i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}
	
	count(str, n);
	printf("%d\n", length);
	return 0;
}

void count(char str[][150], const int n)
{
    int i, k, j;
	char buff[n - 1][150];
	for (i = 0; i < n; i++) {
		char *super = (char *)malloc(150);
		strcpy(super, str[i]);

		for (k = 0, j = 0; k < n; k++) {
			if (k != i) {
				memcpy(buff[j], str[k], 150);
				j++;
			}
		}
		create(super, buff, n - 1, 0);
	} 
}

void create(char super[], char str[][150], const int n, int counter)
{
	if (counter == n) {
		int t = (int)strlen(super);
		if (t < length) length = t;	
		printf("%s: %d\n", super, t);
		free(super);
		return;
	}
	
	if (counter < n) {
		int len = strlen(str[counter]),
			len_s = strlen(super), i;
		
		for (i = 0; i < len; i++) {
			if (i < len_s) {
				if (memcmp(str[counter], super + len_s - i, i) == 0)
					create(append(super, str[counter], i), str, n, counter + 1);
			
			
				if (memcmp(str[counter] + len - i, super, i) == 0)
					create(append(str[counter], super, i), str, n, counter + 1);
			}
		}
	free(super);
	}
}

char* append(char dest[], char src[], const int from)
{
	char* temp = (char *)malloc(150);

	strcpy(temp, dest);
	int len = strlen(temp);
	temp[len - from] = '\0';
	strcat(temp, src);

	return temp;
}