#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10
#define MAX_LEN 10000
int permut(int *arr, int arr_size, int m, int *c, int c_size);
char **str_arr;
char *dest_buf;
int min_len=-1;

int main() 
{
        int str_count;
        int i;
        int inds[MAX];
	int new_arr[MAX];
	int new_arr_size=0;
	int sum_len=0;
        scanf("%d ", &str_count);
	for (i=0; i<str_count; i++) {
		inds[i]=i;
	}
        str_arr = (char **) malloc(str_count*sizeof(char*));
        for (i=0; i<str_count; i++) {
                str_arr[i]=(char*) malloc(MAX_LEN);
                gets (str_arr[i]);
		sum_len+=strlen(str_arr[i]);
        }
	dest_buf=malloc((sum_len+str_count)*sizeof(char));
	permut(inds, str_count, str_count, new_arr, new_arr_size);
	printf("%d\n", min_len);
	for (i=0; i<str_count; i++) {
		free (str_arr[i]);
	}
	free (dest_buf);
	free (str_arr);
	return 0;
}

int permut(int *arr, int arr_size, int m, int *p, int p_size)
{
	int i, j, q;
	int elem;
	long sum;
	int new_arr[MAX];
	int new_arr_size;
	int res_len;
	if (m==0) {
		res_len=str_plus(p, p_size, dest_buf);
		if (min_len==-1 || min_len>res_len) {
			min_len=res_len;
		}
	}
	else {
		for (q=0; q<arr_size; q++) {
			new_arr_size=0;
			for (j=0; j<arr_size; j++) {
				if (j==q) {
					continue;
				}
				new_arr[new_arr_size++]=arr[j];
			}
			p[p_size]=arr[q];
			permut(new_arr, new_arr_size, m-1, p, p_size+1);
		}
	}
}

int str_plus(int *cur_permut, int permut_size, char *dest_buf)
{
	int suf_id, suf_len;
	char *head_str;
	char *tail_ptr;
	if (permut_size==1) {
		strcpy(dest_buf, str_arr[cur_permut[0]]);
		return (strlen(str_arr[cur_permut[0]]));
	}
	else {
		head_str=str_arr[cur_permut[0]];
		tail_ptr=dest_buf+strlen(str_arr[cur_permut[0]])+1;
		str_plus(cur_permut+1, permut_size-1, tail_ptr);
		for (suf_id=0; suf_id<strlen(head_str); suf_id++) {
			if (strlen(head_str+suf_id)>strlen(tail_ptr)) {
				continue;
			}
			if (memcmp(head_str+suf_id, tail_ptr, strlen(head_str+suf_id))==0) {
				break;
			}
		}
		suf_len=strlen(head_str)-suf_id;
		strcpy(dest_buf, head_str);
		strncat(dest_buf, tail_ptr+suf_len, 1);
		return (strlen(dest_buf));
	}
}