//
//  main.c
//  superstr.c
//
//  Created by Владимир Антипов on 29.11.14.
//  Copyright (c) 2014 Владимир Антипов. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* SubStrEnd(const char* source, int shift) {
        int size1 = strlen(source) - shift;
	char* substr1 = (char*)malloc(size1 + 1);
	strncpy(substr1, source + shift, size1);
	substr1[size1] = 0;
	return substr1;
}

char* SubStrStart(const char* source, int shift) {
	int size1 = shift;
	char* substr1 = (char*)malloc(size1 + 1);
	strncpy(substr1, source, size1);
	substr1[size1] = 0;
	return substr1;
}

char* Merge(char* s1, char* s2, int len) {
	int size2 =  strlen (s2)  - len;

	int size = strlen(s1) + size2;

	char* str = (char*)malloc(size + 1);

	char* sub = SubStrEnd(s2, len);

	strncpy( str, s1, strlen(s1));

	strncpy(str + strlen(s1), sub, size2);

	str[size] = 0;

	free(sub);

	return str;
}

int overlap(char* str1, char* str2) {
	int str1last = strlen(str1) - 1;
	int str2Len = strlen(str2);
	int overlap = 0;

	int i, j;

	for(i = str1last, j = 1; i > 0 && j < str2Len; i--, j++) {
		char* substr1 = SubStrEnd(str1, i);
		char* substr2 = SubStrStart(str2, j);
		if(strcmp(substr1, substr2) == 0)
			overlap = j;
		free(substr1);
		free(substr2);
	}

	return overlap;
}

void RemoveNull(char* strings[], int count) {
	int i, index;

	for(i = 0, index = 0; i <  count - index; ) {
		if(strings[i + index] == NULL) {
			index++;
			continue;
		}

		strings[i] = strings[i + index];
		i++;
	}
}

char* CreateSuperString(char* strings[], int count) {
	while (count > 1) {
		int maxoverlap = 0;

		int msi = 0, msj = 1;

		int i = 0 , j = 0;

		for(i = 0; i < count; i++) {
			for(j = 0; j < count; j++) {
				if(strcmp(strings[i], strings[j]) == 0)
					continue;

				int curoverlap = overlap(strings[i], strings[j]);
				
				if(maxoverlap < curoverlap) {
					maxoverlap = curoverlap;
					msi = i; msj = j;
				}
			}
		}

		char* str = Merge(strings[msi], strings[msj], maxoverlap);
		strings[msi] = NULL;
		strings[msj] = NULL;
		RemoveNull(strings, count);
		--count;
		strings[count - 1] = str;
	}

	return strings[0];
}
char ar[10][1000], *strings[100];

int count[10];

int main(int argc, const char * argv[]) {
	int i = 0, n = 0;
    
    scanf("%d\n", &n);
    for(i = 0; i < n; ++i) {
        count[i] = 1;
    }
    for(i = 0; i < n; i++) {
		strings[i] = ar[i];
		gets(strings[i]);
    }
    char* result = CreateSuperString(strings, n);
	

	printf("%d",  strlen(result));

	return 0;
}