#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DL_STR 100

unsigned long overlap(char *s, char *s1);

void merge (char *s, char *s1, unsigned long max_ov) {
    unsigned long l1 = strlen(s), l2 = strlen(s1);
    int i;
    for (i = 0; i < l2 - max_ov; i++)
    {
        s[i + l1] = s1[max_ov + i];
    }
    s[l1+l2-max_ov] = '\0';
}

int main(int argc, const char * argv[])
{
    int i, j, n, temp = 0, temp1 = 0, count_n;
    unsigned long q, max_ov = 0, answer = 0;
    scanf("%d\n", &n);
    count_n = n;
    int help[n];
    for(i = 0; i < n; ++i)
    {
        help[i] = 1;
    }
    char str[n][DL_STR];
    char *mas[n];
    for(i = 0; i < n; i++)
    {
        mas[i] = str[i];
        fgets(mas[i], DL_STR, stdin);
        *(mas[i] + strnlen(mas[i], DL_STR) - 1) = '\0';
    }
    while(count_n > 1)
    {
        max_ov = 0, temp = 0, temp1 = 0, q = 0;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(help[i] != 0 && help[j] != 0 && (i != j))
                {
                    q = overlap(mas[i], mas[j]);
                    if(q >= max_ov)
                    {
                        temp = i;
                        temp1 = j;
                        max_ov = q;
                    }
                }
            }
        }
        merge(mas[temp], mas[temp1], max_ov);
        help[temp1] = 0;
        --count_n;
    }
    for(i = 0; i < n; ++i)
    {
        if(help[i] != 0) answer = strlen(mas[i]);
    }
    printf("%ld\n", answer);
    return 0;
}

unsigned long overlap(char *s, char *s1)
{
    unsigned long i, j, result = 0, k, l = 0;
    unsigned long dl1 = strlen(s)-1, dl2 = strlen(s1);
    for(i = dl1; i > 0 && l < dl2; i--, l++)
    {
        k = i;
        for(j = 1; j <= dl2 && k <= dl1; j++)
        {
            if(s[k++] == s1[j-1])
            {
                if(j > result && s[k]== '\0') result = j;
            }
            else break;
        }
    }
    return result;
}