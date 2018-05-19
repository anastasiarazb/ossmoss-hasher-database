#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int createSuper(char str[][100], const int n);
void creating(char str[][100], const int n, int counter, char super[], int* length);

int main()
{
        int n, i;
        scanf("%d", &n);

        char str[n][100];
	for (i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}

	printf("%d\n", createSuper(str, n));
	return 0;
}

int createSuper(char str[][100], const int n)
{
    int length = 100;

    char *super = (char *)malloc(100);

    strcpy(super, str[0]);

    creating(str, n, 1, super, &length);
    return length;
}

void creating(char str[][100], const int n, int counter, char super[], int* length)
{
    if (counter < n) {
    int i, j, k;

    for (i = 0; i < (int)strlen(str[counter]); i++) {

        int flag = 1;
        for (j = 0; j < (int)strlen(str[counter]) - i; j++)
	   if (j < strlen(super)) {            
		if (str[counter][i + j] != super[j])  flag = 0;
	   } else flag = 0;

        if (flag) {
            char* temp = (char *)malloc(100);

            for (j = 0; j < i; j++)
                temp[j] = str[counter][j];
            temp[i] = '\0';

            strcat(temp, super);
            creating(str, n, counter + 1, temp, length);
        }

        flag = 1;
        for (j = 0, k = strlen(super) - strlen(str[counter]) + i; (j < (strlen(str[counter]) - i)); j++) {
            if ((k + j) > -1) {
                 if (str[counter][j] != super[k + j])
                   flag = 0;
            }
        }


        if (flag) {
            char* temper = (char *)malloc(100);
            temper[0] = '\0';
            strcpy(temper, super);
            int x = strlen(temper);
            for (j = 0; j < i; j++)
                temper[x + j] = str[counter][strlen(str[counter]) - i + j];
            temper[x + i] = '\0';

            creating(str, n, counter + 1, temper, length);
        }
    }

        char* a = (char *)malloc(100);
        char* b = (char *)malloc(100);
        a[0] = '\0';
        b[0] = '\0';

        strcpy(a, super);
        strcpy(b, str[counter]);
        strcat(b, super);
        strcat(a, str[counter]);

        creating(str, n, counter + 1, a, length);
        creating(str, n, counter + 1, b, length);
    }

    if (counter == n) {
        if ((*length) > (int)strlen(super)) (*length) = (int)strlen(super);
        free(super);
        return;
    }

    free(super);
}
