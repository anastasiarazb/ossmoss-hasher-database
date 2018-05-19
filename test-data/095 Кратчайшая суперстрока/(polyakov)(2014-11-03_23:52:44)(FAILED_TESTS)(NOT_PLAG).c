#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define num 10
#define bit 1024

int pref (char *s);
int maximum (int **d, int a, int m, int *mass3, int *c, int *mass);

int main (int argc, char **argv)
{
    char matr1[num][bit] = {0}, mass4[bit] = {0};
    int n, i, j, k = 0, a;
    int p, t = 0, w;
    int r = 0, count = 0;
        
    scanf("%d", &n);
    
    int **mass = (int**)calloc(n, sizeof(int*));
    
    for (i = 0; i < n; i++) 
    {
        *(mass + i) = (int*)calloc(n, sizeof(int));
        j = 0;
        
	while (j <= (n - 1))
        {
            mass[i][j] = 0;
            j++;
        }
    }

	for (i = 0; i < n; i++)
        {
            scanf("%s", &matr1[i]);
        }
        i = n;
	while (i <= (num - 1))
        {
            strcpy(matr1[i], "");
            i++;
        }
        
        i = 0;
        
	while (i <= (n - 1))
	{
            t = strlen(matr1[i]);
            r += t;
            
            for (j = 0; j < n; j++)
            {
		if (i == j)
                {
                    continue;
                }
		w = strlen(matr1[j]);
                
                if (w >= t, k = t)
                {
                    k = w;
                }
                k;
                
		while (k > 0)
		{
                    strcpy(mass4, (matr1[i] + (t - k)));
                    strncat(mass4, matr1[j], k);
                    p = pref(mass4);
                    
                    if (p)
                    {
                        mass[i][j] = k;
                        break;
                    }
                    k--;
		}
            }
            i++;
	}
        
	int *mass1 = (int *)calloc(n, sizeof(int));
	int *mass2 = (int *)calloc(n, sizeof(int));
        
	for (i = 0; i < n; i++)
        {
            mass1[i] = i;
        }
        
	maximum(mass, n, n, mass2, &count, mass1);
        a = r - count;
        
	printf ("%d", a);
        
	free(mass1);
	free(mass2);
        
	for(i = 0; i < n; i++)
        {
            free(mass[i]);
        }
        
	free(mass);
        
	return 0;
}

int maximum (int **d, int a, int m, int *mass3, int *c, int *mass)
{
    int i, j;
    int mass2[num], max;
    max = 0;
        
    if (a != 0)
    {
        i = 0;
        while (i <= (a - 1))
        {
            *(mass3 + (m - a)) = *(mass + i);
            j = 0;
            while (*(mass + i) != *(mass + j))
            {
                *(mass2 + j) = *(mass + j);
                j++;
            }
            j;
            while (j <= (a - 2))
            {
                *(mass2 + j) = *(mass + (j+1));
                j++;
            }
            maximum(d, a - 1, m, mass3, c, mass2);
            i++;
            }
    }
    else
    {
        {
            i = 0;
            while (i <= m - 2)
            {
                max += d[mass3[i]][mass3[i+1]];
                i++;
            }
            if (max > *c)
            {
                *c = max;
            }
        }
    }
}

int pref (char *s)
{
    int i, half;
    int length = strlen(s), p;
        
    half = length / 2;
    i = 0;
    p = 1;
        
    while (i <= (half - 1))
    {
        if (*(s + i) != *(s + i + half))
        {
            p = 0;
        }
        i++;
        }
        return p;
}