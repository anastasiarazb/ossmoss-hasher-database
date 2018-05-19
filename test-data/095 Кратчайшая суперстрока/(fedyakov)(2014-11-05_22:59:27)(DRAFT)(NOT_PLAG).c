#include <stdio.h>
#include <string.h>

int array [10], strlens [10];
char *str_pointers [10];
char str [10] [100];
char superstr[1000];
int spstr_len;
int flagstrremove [10];

void merge_s (char *s1, char *s2, unsigned long ovl) {
    unsigned long length1 = strlen(s1);
    unsigned long length2 = strlen(s2);
    int i = 0;
    for (i = 0; i < length2 - ovl; i++)
        s1[i + length1] = s2[ovl + i];
}

int compare_s (char *s1, char *s2, unsigned long i, unsigned long length1, unsigned long j) {
    int flag = 1;
    int k = 0;
    if (!(i < length1 && k <= j)) return 0;
    for (; i < length1 && k <= j; i++, k++) {
	if (!(s1 [i] == s2[k]))  {
	    flag = 0;
	    break;
	}
    }
    return flag;
}
    
int overlap (char *s1, char *s2) {
    int len1 = strlen (s1);
    int len2 = strlen (s2);
    int i = len1 - 1, j = 0;
    int result = 0;
    char *suff, *pref;
    
    for (; (i >= 0) && (j < len2); i--, j++) {
	if (compare_s (s1, s2, i, len1, j)) {
	    //debug: printf("i = %d, j = %d, ", i, j);
	    result = j + 1;
	    //debug: printf ("temp overlap = %d\n", result);
	}
    }
    return result;
}

void formsuperstr (int n, int count) {
    int maxovlp = 0, im = 0, jm = 0, currentovlp = 0;
    int i,j;
    printf ("count = %d\n", count);
    
    if (count == 1) {
	for (i = 0; i < n; i++)
	    if (flagstrremove[i]) spstr_len = strlen(str_pointers[i]);
    }
    else {
    for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
	    if (flagstrremove[i] && flagstrremove [j] && (i != j)) {
		currentovlp = overlap (str_pointers[i], str_pointers[j]);
		if (currentovlp > maxovlp) {
		    maxovlp = currentovlp;
		    im = i;
		    jm = j;
		}
	    }
	}
    }
    printf ("merging inside %d - %d with overlap = %d\n", im, jm, maxovlp);
    merge_s (str_pointers [im], str_pointers [jm], maxovlp);
    flagstrremove [jm] = 0;
    formsuperstr (n, count - 1);
    }
}

int main()
{ 
    int i;
    int n;
    scanf("%d ", &n); 
   
	
    
    /* Считаем строки и свяжем указатели */
    for (i = 0; i < n; i++) {
	array[i] = 0;
	gets (str[i]);
	str_pointers[i] = str[i];
	strlens[i] = strlen(str_pointers[i]);
	flagstrremove[i] = 1;
    }
    for (i = n; i < 10; i++)
	flagstrremove[i] = 0;
    formsuperstr (n,n);
    for (i = 0; i < n; i++) {
	if (flagstrremove[i]) printf ("superstr found = %s\n", str_pointers[i]);
    }
    printf("spstr_len = %d\n", spstr_len);
    /*int ovlp = overlap (str_pointers[0], str_pointers[1]);
    printf ("%d\n", overlap (str_pointers[0], str_pointers[1]));
    merge_s (str_pointers[0], str_pointers[1], ovlp);
    printf("%s\n", str_pointers[0]);
    */
    
	return 0;
}
