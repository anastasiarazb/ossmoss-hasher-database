#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void addzero(char *first, char *second, int maximum);
int searchCtd(char *T, char *S);

int main()
{
        int n, i, j, k, max, first, second, counter;
	char **the_strings;

    scanf("%d", &n);
	the_strings = calloc(n, sizeof(char*));
	for (i = 0; i < n; i++)
		the_strings[i] = calloc(100, sizeof(char));


	for (i = 0; i < n; i++)
        scanf("%s", the_strings[i]);


	for (k = 1; k < n; k++)
	{
		for (i = 0,  max = -1; i < n; i++)
        {
			for (j = 0; j < n; j++)
				if (the_strings[i][0] && the_strings[j][0] && i != j)
				{
					int curent = searchCtd(the_strings[i], the_strings[j]);
					if (curent > max)
						max = curent, first = i, second = j;
				}
        }
		addzero(the_strings[first], the_strings[second], max);
		counter = first;
	}
	printf("%d\n", (int) strlen(the_strings[counter]));


	/*CLEANUP*/
	for (i = 0; i < n; i++)
		free(the_strings[i]);
	free(the_strings);
	return 0;
}


void addzero(char *f, char *s, int maximum)
{
	f[strlen(f) - maximum] = '\0';
	strcat(f, s);
	s[0] = '\0';
}

int searchCtd(char *the_strings_i, char *the_strings_j)
{
	int i = 1, k = 0, j, counter = 0;
	for (;the_strings_i[i];i++)
	{
	    k = 0;
		for (j = i; (the_strings_i[j] && the_strings_j[k]) != 0; j++,k++)
        {
            if (the_strings_i[j] != the_strings_j[k])
			{
				k = 0;
				break;
			}
        }
		if (k > counter) counter = k;

	}
	return counter;
}