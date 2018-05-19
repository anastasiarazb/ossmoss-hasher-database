#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N;
int min = 0;
int len;
char** a;
void QuickPerm(int** array, int* Numb);
int Check(int l, int k);

int main(int argc, char** argv) {
        int i, f;
        scanf("%d", &N);
        int numbers[N];
        int** array = (int**)malloc(N*sizeof(int*));
        a = (char**)malloc(N*sizeof(char*));
        for(i = 0; i < N; i++) {
                	a[i] = (char*)calloc(256, sizeof(char));
	        	scanf("%s", a[i]);
	        	min += strlen(a[i]);
	        	len = min;
      	}    
      	for(i = 0; i < N; i++) {
                array[i] = (int*)malloc(N*sizeof(int));
      	        numbers[i] = i;
       }
      	for(i = 0; i < N; i++)
      	        for(f = 0; f < N; f++) {
                        array[i][f] = 0;
                        if(i != f)
      	                       array[i][f] = Check(i, f);
                        }
    	QuickPerm(array, numbers);
    	for(i = 0; i < N; i++) {
                free(array[i]);
	        	free(a[i]);
             }
        free(array);
    	printf("%d", min);
        return 0;
}


int Check(int l, int k) {
    int i = 0, c = 0;
    while(a[l][c]) {
        while(a[l][c+i] == a[k][i]) {
            i++;
            if(a[l][c+i] == '\0') 
                return i;
        }
        i = 0;
        c++;
    }
    return i;
}
    
void QuickPerm(int** array, int* Numb) {
        unsigned int p[N+1];
        unsigned int i, j, k, min1 = 0;
        int tmp;
        for(k = 1; k < N; k++)
		    min1 += array[k-1][k];
        if(len - min1 < min) min = len - min1;
        min1 = 0;
        for(i = 0; i < N; i++) 
                p[i] = i;
        p[N] = N;    
        i = 1;  
        while(i < N)
        {
                p[i]--;          
                j = i % 2 * p[i];  
                tmp = Numb[j];       
                Numb[j] = Numb[i];
                Numb[i] = tmp;
                for(k = 1; k < N; k++)
	          	        min1 += array[Numb[k-1]][Numb[k]];
                if(len - min1 < min) 
                        min = len - min1;
                min1 = 0;
                i = 1;           
                while (!p[i])      
                {
                p[i] = i;    
                i++;          
                }
        }
}
