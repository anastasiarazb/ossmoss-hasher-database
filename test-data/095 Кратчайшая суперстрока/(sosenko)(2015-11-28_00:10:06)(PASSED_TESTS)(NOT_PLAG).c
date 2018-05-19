#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calc_overlap (char* superstring, char* nextstring)
{
    int first_i;
    int first_k;
    int second_i;
    int first_l = strlen(superstring);
    int overlap = 0;
    for (first_i = 0; first_i < first_l; first_i++)
    {
        second_i = 0;
        first_k = first_i;
        while (superstring[first_k] && nextstring[second_i])
        {
            if (superstring[first_k] != nextstring[second_i])
            {
                overlap = 0;
                break;
            }
            else
            {
                overlap++;
                first_k++;
                second_i++;
            }
        }
        if (0 < overlap)
        {
            break;
        }
    }
    return overlap;
}

void aggregate_superstring(char* superstring, char* nextstring, int over)
{
    int i;
    int j;
    for (i = strlen(superstring), j = over; nextstring[j] != '\0'; i++, j++)
    {
        superstring[i] = nextstring[j];
    }
    superstring[i] = '\0';
    nextstring[0] = '\0';
}

int main()
{
        int i;
        int n;
        int k;
        int j;
        int result;
        scanf ("%d", &n);
        char** s = (char**)malloc(n*sizeof(char*));
        for (i = 0; i < n; i++)
        {
                s[i] = (char*)malloc(256*sizeof(char));
                scanf ("%s", s[i]);
        }

        char* superstring;
        for (k = 0; k < n - 1; k++)
        {
            int max = -1;
            int max_i = -1;
            int max_j = -1;

            for (i = 0 ; i < n; i++)
            {
                if (strlen(s[i]) == 0)
                    continue;
                for (j = 0; j < n; j++)
                {
                    if (strlen(s[j]) == 0)
                        continue;
                    if (i != j)
                    {
                        int over = calc_overlap(s[i], s[j]);
                        if (max < over)
                        {
                            max = over;
                            max_i = i;
                            max_j = j;
                        }
                    }
                }
            }
            aggregate_superstring (s[max_i], s[max_j], max);
            superstring = s[max_i];
        }

        result = strlen(superstring);
        for (i = 0; i < n; i++)
        {
                free(s[i]);
        }

        free(s);
        printf("%d", result);
        return 0;
}
