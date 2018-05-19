#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* aggregate_superstring(char* superstring, char* k)
{
        int newlength = strlen(superstring) + strlen(k) + 1;
        char* result = (char*)malloc(newlength * sizeof(char));
        int first_i = 0;
        int second_i = 0;
        while (superstring[first_i] != '\0')
        {
                if (superstring[first_i] != k[second_i] || k[second_i] == '\0')
                {
                        if (superstring[first_i] == k[0])
                        {
                                second_i = 0;
                        }
                        else
                        {
                                second_i = -1;
                        }
                }
                result[first_i] = superstring[first_i];
                first_i++;
                second_i++;
        }
        
        while (k[second_i] != '\0')
        {
                result[first_i] = k[second_i];
                first_i++;
                second_i++;
        }
        
        result[first_i] = '\0';
        return result;
}

int pere(char* superstring, char** strarray, int n)
{
        int i;
        int j;
        if (n == 0)
        {
                return strlen(superstring);
        }
        
        int minimal_super_length = 10 * 256;
        for (i = 0; i < n; i++)
        {
                char** subarr = (char**)malloc((n-1) * sizeof(char*));
                char* k = strarray[i];
                int z = 0;
                for (j = 0 ; j < n; j++)
                {
                        if (i != j)
                        {
                                subarr[z] = strarray[j];
                                z++;
                        }
                }
                char* aggregated = aggregate_superstring(superstring, k);
                int current_length = pere(aggregated, subarr, n-1);
                free (aggregated);
                minimal_super_length = minimal_super_length < current_length ? minimal_super_length : current_length;
                free(subarr);
        }
        return minimal_super_length;
}

int main()
{
        int i;
        int n;
        scanf ("%d", &n);
        char** s = (char**)malloc(n*sizeof(char*));
        for (i = 0; i < n; i++)
        {
                char* current_s = (char*)malloc(256*sizeof(char));
                scanf ("%s", current_s);
                s[i] = current_s;
        }
        
        char* superstring = (char*)malloc(sizeof(char));
        superstring[0] = '\0';
        int t = pere(superstring, s, n);
        for (i = 0; i < n; i++)
        {
                free(s[i]);
        }
        free(s);
        free(superstring);
        printf("%d", t);
        return 0;
}