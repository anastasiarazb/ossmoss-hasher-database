#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void QuickPerm();
int N;
char** a;
int min = 0;

int main() {
    int i;
    scanf("%d", &N);
        a = (char**)malloc(N*sizeof(char*));
    for(i = 0; i < N; i++) {
		a[i] = (char*)malloc(sizeof(char)*512);
		scanf("%s", a[i]);
		min += strlen(a[i]);
	}
	QuickPerm();
	for(i = 0; i < N; i++)
		free(a[i]);
	free(a);
	printf("%d", min);
        return 0;
}

int Prefix(int l, int k) {
    int i, t = 0, len1 = strlen(a[l]), len2 = strlen(a[k]);
	int array[2*(len1-1)];
    for(i = 0; i < 2*(len1-1); i++) 
            array[i] = 0;
    for(i = 1; i < len1-1; i++) {
	    while(t > 0 && a[l][i] != a[l][t])
		    t = array[t-1];
	    if(a[l][i] == a[l][t])
		    ++t;
	    array[i] = t;
	}
	--i;
	for(i = 0; i < len1-1; i++) {
		while(t > 0 && a[l][t] != a[k][len2-len1+1+i])
			t = array[t-1];
		if(a[l][t] == a[k][len2-len1+1+i])
			++t;
		array[i+len1-1] = t;
	}
	return array[2*len1 - 3];
}


void QuickPerm() {
        unsigned int p[N+1];
        unsigned int i, j, k, min1;
        char* tmp;
        min1 = strlen(a[0]);
        for(k = 1; k < N; k++)
		min1 += strlen(a[k]) - Prefix(k, k-1);
        if(min1 < min) min = min1;
        for(i = 0; i < N; i++) 
        { 
                p[i] = i;
        }
        p[N] = N;    
        i = 1;  
        while(i < N)
        {
                p[i]--;          
                j = i % 2 * p[i];  
                tmp = a[j];       
                a[j] = a[i];
                a[i] = tmp;
        	min1 = strlen(a[0]);
                for(k = 1; k < N; k++)
	          	  min1 += strlen(a[k]) - Prefix(k, k-1);
                if(min1 < min) min = min1;
                i = 1;           
                while (!p[i])      
                {
                p[i] = i;    
                i++;          
                }
        }
}
