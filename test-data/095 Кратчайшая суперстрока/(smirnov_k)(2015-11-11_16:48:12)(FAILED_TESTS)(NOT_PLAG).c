#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned gen(int* mr, int* mi, char** ms, int k, int n, unsigned lenmin);
void printmas(char** ms, int* mi, int n);
void copymas(int* mr, int* mi, int n);
void swap (int* Pb, int* Pe);

unsigned minlen(char** ms, int* mi, int n);
char* strunion(char* s1, char* s2);

int main()
{

        int n;
	scanf("%d", &n);
	
	int mres[n];
	int m[n];
	int i;
	for(i = 0; i < n; m[i] = i, i++);

	char** Mst = malloc(n * 1000);
	for(i = 0; i < n; i++) {
		Mst[i] = malloc(1000);
		scanf("%s", Mst[i]);
	}
		
	copymas(mres, m, n);
	unsigned len = minlen(Mst, mres, n);
	
	len = gen(mres, m, Mst, 0, n, len);
	
	printf("%d\n", len);

	for(i = 0; i < n; i++) {
		free(Mst[i]);
	}
	free(Mst);
	
	return 0;
}

void swap (int* Pb, int* Pe)
{
	int temp = *Pb;
	*Pb = *Pe;
	*Pe = temp;
}


unsigned gen(int* mr, int* mi, char** ms, int k, int n, unsigned lenmin)
{
	int i;
	for(i = k; i < n; i++)
	{
		swap(&mi[k], &mi[i]);
		if(k + 1 == n - 1)
		{
			unsigned len = minlen(ms, mi, n);
			
			if(lenmin > len)
			{
				copymas(mr, mi, n);
				lenmin = len;
			}
		}
		lenmin = gen(mr, mi, ms, k + 1, n, lenmin);
		swap(&mi[k], &mi[i]);
	}
	
	return lenmin;
}

void copymas(int* mr, int* mi, int n)
{
	int i;
	for(i = 0; i < n; i++)
		mr[i] = mi[i];
}

char* allocst(char** ms, int n)
{
	unsigned len = 1;
	
	unsigned i;
	for(i = 0; i< n; i++)
		len += strlen(ms[i]);
		
	char* stemp = (char*)malloc(len);
	
	return stemp;
}

unsigned minlen(char** ms, int* mi, int n)
{
	char* stemp = allocst(ms, n);
	
	int i;
	strcpy(stemp, ms[mi[0]]);
	for( i = 1; i < n; i++)
		strunion(stemp, ms[mi[i]]);	
			
	unsigned len = strlen(stemp);	
	
	free(stemp);	
	
	return len;
}

char* strunion(char* s1, char* s2)
{
	unsigned len1 = strlen(s1);
	unsigned i;
	unsigned k = 0;
	for(i = 1; i < len1; i++)
		if(strstr(s2, s1 + len1 - i) == s2)
		{
			k = i;
		}
	
	strcat(s1, s2 + k);
	
	return s1;	
}