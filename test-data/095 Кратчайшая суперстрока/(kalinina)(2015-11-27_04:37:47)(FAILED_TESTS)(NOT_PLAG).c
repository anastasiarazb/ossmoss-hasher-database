
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GetOverlapedSuffixLength(char *left, char *right)
{
        int i, curLength, res;
	curLength = 0;
	res = 0;
	for (i = 1; left[i] != 0; i++) {
		curLength = 0;
		while ((left[i + curLength] != '\0') && (right[curLength] != '\0')) {
			if (left[i + curLength] != right[curLength]) {
				curLength = 0;
				break;
			}
			curLength++;
                }
                if (res < curLength) res = curLength;
	}
	return res;
}


int main(int argc, char **argv) 
{	
	char** words;
        int n, i, j, k, max, first, second;
        scanf("%d", &n);
	words = (char**)calloc(n, sizeof(char*));
	for (i = 0; i < n; i++) {
		words[i] = (char*)calloc(100, sizeof(char));
		scanf("%s", words[i]);
	}
	for (k = 1; k < n; k++) {
                max = -1;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if ((i != j) && (words[i][0] != '\0') && (words[j][0] != '\0')) {
					int currentLength = GetOverlapedSuffixLength(words[i], words[j]);
					if (currentLength > max) {
						max = currentLength;
                                                first = i;
                                                second = j;
                                        }
                                }
                        }
		}
                words[first][strlen(words[first])-max] = '\0';
                strcat(words[first],  words[second]);
                words[second][0] = '\0';
	}
	printf("%d\n", (int)strlen(words[first]));
        free(words);
	return 0;
}