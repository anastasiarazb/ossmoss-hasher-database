#include <stdio.h>
#include <string.h>
char str[10][1000], *mas[10];
long int answer, used[10] ;

void merge (char *s, char *s1, unsigned long max_ov) {
    unsigned long l1 = strlen(s), l2 = strlen(s1);
    int i;
    for (i = 0; i < l2 - max_ov; i++)
    {
        s[i + l1] = s1[max_ov + i];
    }
}

int overlap(char *a, char *b)
{
    int count = 0, i = 0, j;
    long int z;
    z = strlen(a);
    for(j = 1; z > j; j ++ )
    {
        if(a[j] == b[i])
        {
            ++ count;
            ++ i;
        }
        else
        {
            if(count != 0)
                j -= count;
            i = count =  0;
        }
    }
    return count;
}

void superString(int n, int amount)
{
    int i, maxoverlap = 0, temp = 0, temp1 = 0, currentoverlap = 0, j;
    if (amount == 1)
    {
        for (i = 0; i < n; i++) {
            if (used[i] != 0) {
                answer = strlen(mas[i]);
            }
        }
    }
    else
    {
        for (i=0; i<n; i++) {
            for (j =0; j < n; j++) {
                if (used[i] != 0 && used[j] != 0 && i!=j) {
                    currentoverlap = overlap(mas[i], mas[j]);
                    if (currentoverlap >= maxoverlap) {
                        temp = i;
                        temp1 = j;
                        maxoverlap = currentoverlap;
                    }
                }
            }
        }
        merge(mas[temp], mas[temp1], maxoverlap);
        used[temp1]=0;
        amount--;
        superString(n, amount);
    }
}


int main(int argc, const char * argv[]) {
    int n, i;
    scanf("%d", &n);
    for (i=0; i < n; i++) {
        used[i] = 1;
    }
    for (i=0; i<n; i++) {
        mas[i] = str[i];
        gets(mas[i]);
    }
    superString(n,n);
    printf("\n%ld\n", answer);
    
    return 0;
}

