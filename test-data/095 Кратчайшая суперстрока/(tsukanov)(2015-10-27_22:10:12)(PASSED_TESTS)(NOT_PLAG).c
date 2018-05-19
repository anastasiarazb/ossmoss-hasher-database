#include <stdio.h>
#include <stdlib.h>

int sum_len = 0;
int min_len = 0;

// мемоизация
int calc_mem[10][10];

int calc(char *array[], int n, int m)
{
    if (calc_mem[n][m] != -1)
        return calc_mem[n][m];

    char *prev = array[n];
    char *next = array[m];

    int len = strlen(prev), i;
    for (i = 0; i < len; i++)
        if (strncmp(&prev[i], next, len - i) == 0)
        {
            calc_mem[n][m] = len - i;
            return len - i;
        }

    calc_mem[n][m] = 0;
    return 0;
}

int superlen(char *array[], int count, int *index)
{
    int i;
    int len = sum_len;

    for (i = 1; i < count; i++)
    {
        int step = calc(array, index[i - 1], index[i]);
        len -= step;
    }

    return len;
}

int permut_rec(char *array[], int count, int *index, int current, char *used_index)
{
    // index - использованные индексы
    if (current == count)
    {
        // index тут - какая-то перестановка
        int len = superlen(array, count, index);
        if (min_len == 0 || len < min_len)
            min_len = len;
    }
    else
    {
        int i, j;
        for (i = 0; i < count; i++)
        {
            // проверка, использован ли уже этот индекс
            if (used_index[i] == 1)
                continue;

            index[current] = i;
            used_index[i] = 1;
            permut_rec(array, count, index, current + 1, used_index);
            used_index[i] = 0;
        }
    }
}

int permut(char *array[], int n)
{
    int index[n], i, j;
    char used_index[n];

    for (i = 0; i < n; i++)
        used_index[i] = 0;

    for (i = 0; i < n; i++)
        sum_len += strlen(array[i]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            calc_mem[i][j] = -1;

    permut_rec(array, n, index, 0, used_index);
}

int main()
{
    int n, i;

    scanf("%d\n", &n);

    char* str[n];

    for (i = 0; i < n; i++)
    {
        str[i] = (char *)malloc(1024);
        gets(str[i]);
    }

    permut(str, n);
    printf("%d\n", min_len);

    for (i = 0; i < n; i++)
    {
        free(str[i]);
    }

    return 0;
}
