        #include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	int flags[10], res = 0;
	char a[10][1000], *strings[100];

	unsigned long overlap(char *a, char *b) {
		int c1 = 1, c2 = 0;
		unsigned long result = 0;
		
		for (c1; c1 < strlen(a); c1++) {
			if (a[c1] != b[c2]) {
				if (result != 0)
					c1 -= result;
				c2 = 0;
				result = 0;
			} else {
				c2++;
				result++;
			}
		}
		return result;
	}

	void merge(char *first, char *second, unsigned long overlap) {
		int counter = 0, LENGTH_FIRST = strlen(first);
		
		for (counter; counter < strlen(second) - overlap; counter++)
			first[counter + LENGTH_FIRST] = second[overlap + counter];
	}

	void super(int n, int amount) {
		int c1 = 0, c2, c_c1 = 0, c_c2 = 0;
		unsigned long TempOL = 0, MaxOL = 0;
		
		if (amount == 1)
			for (c1 = 0; c1 < n; c1++)
				if (flags[c1] != 0)
					res = strlen(strings[c1]);
		else {
			MaxOL = 0;
			TempOL = 0;
			c_c1 = 0;
			c_c2 = 0;
			for (c1 = 0; c1 < n; c1++) {
				for (c2 = 0; c2 < n; c2++)
					if (flags[c1] != 0 && flags[c2] != 0 && c1 != c2) {
						TempOL = overlap(strings[c1], strings[c2]);
						if (TempOL >= MaxOL) {
							MaxOL = TempOL;
							c_c1 = c1;
							c_c2 = c2;
						}
					}
			}
			flags[c_c2] = 0;
			merge(strings[c_c1], strings[c_c2], MaxOL);
			super(n, --amount);
		}
	}
	int main() {
		int SIZE, counter = 0;
		scanf("%d", &SIZE);
		for (counter; counter < SIZE; counter++)
			flags[i] = 1;
			
		for (counter = 0; counter < SIZE; counter++) {
			strings[counter] = a[counter];
			gets(strings[counter]);
		}
		super(SIZE, SIZE);
		printf("%ld", res);
		return 0;
	}