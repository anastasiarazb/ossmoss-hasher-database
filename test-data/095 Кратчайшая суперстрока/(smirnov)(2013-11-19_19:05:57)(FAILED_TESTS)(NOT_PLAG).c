#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int N;
int min = 0;
int len;
char** a;
void QuickPerm(int** array, int* Numb);
int Prefix(int l, int k);

int main(int argc, char** argv) {
        int i, f;
        scanf("%d", &N);
        int array[N][N], numbers[N];
        a = (char**)malloc(N*sizeof(char*));
        for(i = 0; i < N; i++) {
                a[i] = (char*)calloc(256, sizeof(char));
	        scanf("%s", a[i]);
	        min += strlen(a[i]);
	        len = min;
      	}    
      	for(i = 0; i < N; i++)
      	        numbers[i] = i;
      	for(i = 0; i < N; i++)
      	        for(f = 0; f < N; f++) {
                        array[i][f] = 0;
                        if(i != f)
      	                         array[i][f] = Prefix(i, f);
                }
    	for(i = 0; i < N; i++)
	        free(a[i]);
    	free(a);
    	QuickPerm(array, numbers);
    	printf("%d", min);
    	getch();
        return 0;
}

int abs(int i) {
        if(i < 0) return -i;
        else return i;
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
	        while(t > 0 && a[l][t] != a[k][abs(len2-len1+1+i)])
	            	t = array[t-1];
	        if(a[l][t] == a[k][abs(len2-len1+1+i)])
	       		++t;
	        array[i+len1-1] = t;
	    }
	return array[2*len1 - 3];
}

void QuickPerm(int** array, int* Numb) {
        unsigned int p[N+1];
        unsigned int i, j, k, min1 = 0;
        int tmp;
        for(k = 1; k < N; k++)
		min1 += array[k-1][k];
        if(len - min1 < min) min = len - min1;
        for(i = 0; i < N; i++) 
                p[i] = i;
        p[N] = N;    
        i = 1;  
        while(i < N) {
                p[i]--;          
                j = i % 2 * p[i];  
                tmp = Numb[j];       
                Numb[j] = Numb[i];
                Numb[i] = tmp;
                for(k = 1; k < N; k++)
	          	  min1 += array[Numb[k-1]][Numb[k]];
                if(len - min1 < min) min = len - min1;
                i = 1;           
                while (!p[i]) {
                p[i] = i;    
                i++;          
                }
        }
}
