#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int overlap(char suff[], char pref[]);
int count(char str[][150], int n);
void append(char a[], char b[], int overlap);

int main()
{
        int n, i;
        scanf("%d", &n);
        
        char str[n][150];
        for (i = 0; i < n; i++)
        	scanf("%s", str[i]);
        
        printf("%d\n", count(str, n));
        return 0;
}

int overlap(char suff[], char pref[])
{
	int i, k, res = 0;
	for (i = 1; suff[i] != '\0'; i++) {
		for (k = 0; suff[k + i] && pref[k]; k++)
			if (suff[k + i] != pref[k]) {
				k = 0;
				break;
			}
		if (k > res) res = k;
	}
	return res;
}

int count(char str[][150], int n)
{
    int i, j, k, max, first, second, res;

	for (k = 1; k < n; k++) {
		max = -1;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			        if (i != j && (str[i][0] != '\0')
                                           && (str[j][0] != '\0')) {
					int cur = overlap(str[i], str[j]);
					if (cur > max)
						max = cur, first = i, second = j;
				}

		append(str[first], str[second], max);
		res = first;
	}

    return (int)strlen(str[res]);
}

void append(char a[], char b[], int overlap)
{
	a[strlen(a) - overlap] = '\0';
	strcat(a, b);
	b[0] = '\0';
}
