#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t overlap_cnt(char *suffix_first, char *prefix_first) {
        if ( !(*(suffix_first) && *(prefix_first)) )
		return 0;

    size_t overlap = 0;
	char *suffix = suffix_first, *prefix = prefix_first;
	for (; *suffix_first; ++suffix_first, suffix = suffix_first, prefix = prefix_first, overlap = 0)
	{
		do
		{	
			if (*(suffix) != *(prefix))
				break;
			++overlap;
		} while (*(++suffix) && *(++prefix));
		
		if ( !(*(suffix) && *(prefix)) )
			break;	
	}
	
	return overlap;
}

char* merge_strings(char *suffix, char *prefix, size_t number_of_merging_chars)
{
	char *new_string = malloc((strlen(suffix)+strlen(prefix)-number_of_merging_chars+1)*sizeof(char));
	strcpy(new_string,suffix);
	strcat(new_string,prefix+number_of_merging_chars);
	return new_string;
}

char** merge_max_overlapping_strings(char **strings_arr,size_t number_of_strings)
{
	if (number_of_strings < 2)
		return strings_arr;
	
	size_t max = 0, suffix_num = 0, prefix_num = 1;
	size_t i,j;
	for (i = 0; i < number_of_strings; ++i)
		for (j = 0; j < number_of_strings; ++j)
		{
			size_t overlap;
			if ( i != j && (overlap = overlap_cnt(strings_arr[i],strings_arr[j])) > max)
			{
				max = overlap;
				suffix_num = i;
				prefix_num = j;
			}
		}
		
	char *new_string = merge_strings(strings_arr[suffix_num],strings_arr[prefix_num],max);
	free(strings_arr[suffix_num]); free(strings_arr[prefix_num]);
	
	strings_arr[suffix_num] = new_string;
	strings_arr[prefix_num] = strings_arr[number_of_strings-1];
	
	char **new_strings_arr = malloc((number_of_strings-1)*sizeof(char*));
	for (i = 0; i < (number_of_strings-1); ++i)
		new_strings_arr[i] = strings_arr[i];
		
	free(strings_arr);
	
	return new_strings_arr;			
}




#define MAX_CHARACTERS 256

int main()
{
	int N;
	scanf("%d",&N);
	
	char **strings_arr = malloc(N*sizeof(char*));
	
	size_t i;
	for (i=0; i < N; ++i)
		strings_arr[i] = malloc((MAX_CHARACTERS+1)*sizeof(char));
	
	for (i = 0; i < N; ++i)
		scanf("%s",strings_arr[i]);
	printf("\n");
	
	size_t n;
	for (n=N; n > 1; --n)
		strings_arr = merge_max_overlapping_strings(strings_arr,n);
	
	printf("%d\n",
		strlen(strings_arr[0])
	);
	
	free(strings_arr[0]);
	free(strings_arr);
	
	return 0;
}