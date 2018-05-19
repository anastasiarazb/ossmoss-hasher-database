#include <stdio.h>
#include <string.h>
    int array [10], strlens [10];
    char *str_pointers [10];
    char str [10] [100];
    char test [10*100], minstr[1000];
    int minlen;
    int tslen, depth, n;
    
int min (int i, int j) {
    return (i < j) ? i : j;
}
    
void try (int i) {
    int j,k, flag, l;
    int length = strlens[i];
    //printf("launching try\n");
    if (tslen == 0) {
        strcpy (test, str_pointers[i]);
	tslen = length;
    }
    else {
	for (j = 0; j < tslen; j ++){
	    flag = 1;
	    int tmin = min (tslen - j, length);
	    k = 0;
	    while ((k < tmin) && flag) {
		//printf("comparing %c %c\n", str_pointers [i] [k], test [k + j]);
		flag = flag && (str_pointers[i] [k] == test [k + j]);
		k ++;
	    }
	    
	    if (flag && ((j + length) > tslen)) {
		k = tslen - j;
		while (k < length) {
		    
		    test [tslen] = str_pointers [i] [k];
		    tslen++;
		    k++;
		}
		
	    }
	    if (flag) goto out1;
	}
	
	k = 0;
	while (k < length) {
		    
		    test [tslen] = str_pointers [i] [k];
		    tslen++;
		    k++;
	}
	out1: ;
    }
 //for (i = 0; i < min (tslen, 10); i++) printf("%c", test[i]);
// printf("\n");
}
    
void find_superstring () {
   // printf("Launched fss\n");
  int i;
  if (tslen < minlen) {
    for (i = 0; i < n; i++ ) {
	//printf("i = %d\n", i);
	if (!(array[i])) {
	    int temp = tslen;
	    try (i);
	    if (depth < n) {
		depth++;
		array[i] = 1;
		// int temp = tslen;
		find_superstring ();
		// tslen = temp;
		array[i] = 0;
		depth--;
	    }
	    else if (minlen > tslen) { minlen = tslen; strcpy(minstr, test); }
	    tslen = temp;
	}
    }
  }
}


int main()
{
    int i;
    scanf("%d ", &n); 
    //for (i = 0; i < 10; array[i] = 0, i++) ;

    
    /* Считаем строки и свяжем указатели */
    for (i = 0; i < n; i++) {
	array[i] = 0;
	gets (str[i]);
	str_pointers[i] = str[i];
	strlens[i] = strlen(str_pointers[i]);
    }
    depth = 1;
    tslen = 0;
    minlen = 1000;
    find_superstring();
    //printf ("minlen = %d\n superstr = ", minlen);
    //for (i = 0; i < min (minlen, 10); i++) printf("%c", minstr[i]);
    printf("%d\n", minlen);
	return 0;
}
