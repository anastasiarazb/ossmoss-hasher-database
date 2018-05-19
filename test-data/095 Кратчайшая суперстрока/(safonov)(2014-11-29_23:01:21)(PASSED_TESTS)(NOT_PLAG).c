#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// GLOBAL DATA
int strings[10];
unsigned long RESULT = 0;
char data[10][1000], *data_temp[100];


unsigned long Overlap(char *first, char *second) {
        int result = 0, c1 = 1, c2 = 0, LENGTH_FIRST = strlen(first);
	
	for (c1; c1 < LENGTH_FIRST; c1++) {
		if (first[c1] == second[c2]) {
			result++;
			c2++;
		} else {
			if (result != 0)
				c1 -= result;
			result = 0;
			c2 = 0;
		}
	}
	return result;
}

void Merge(char *first, char *second, unsigned long OL) {
	int counter = 0, LENGTH_FIRST = strlen(first), LENGTH_SECOND = strlen(second);

	for (counter; counter < LENGTH_SECOND - OL; counter++)
		first[counter + LENGTH_FIRST] = second[counter+ OL];
}

void SuperString(int size, int amount) {
	if (amount != 1) {
		unsigned long TempOL = 0, MaxOL = 0;
		int c1 = 0, c2, max_c1 = 0, max_c2 = 0;
		
		for (c1; c1 < size; c1++)
			for (c2 = 0; c2 < size; c2++)
				if (strings[c1] != 0 && strings[c2] != 0 & c1 != c2) {
					TempOL = Overlap(data_temp[c1], data_temp[c2]);
					if (MaxOL <= TempOL) {
						MaxOL = TempOL;
						max_c1 = c1;
						max_c2 = c2;
					}
				}
		--amount;
		Merge(data_temp[max_c1], data_temp[max_c2], MaxOL);
		strings[max_c2] = 0;
		SuperString(size, amount);
	} else {
		int counter = 0;
		
		for (counter; counter < size; counter++)
			if (strings[counter] != 0)
				RESULT = strlen(data_temp[counter]);
	}
}

int main() {
	int counter = 0, size;
	
	scanf("%d\n", &size);
	for (counter; counter < size; counter++) {
		data_temp[counter] = data[counter];
		scanf("%s", data_temp[counter]);
		strings[counter] = 1;
	}
	
	SuperString(counter, counter);
	
	printf("%ld\n", RESULT);
	return 0;
}