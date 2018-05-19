#include <stdio.h>
#include <string.h>
char a[10][1000], *strtemp[10], used[10] = {0};
int answer;
void substring(char* string, char* substring, int left, int right)
{
    int i, j;
    for (i=left, j=0; i < right; i++, j++)
        substring[j]=string[i];
    
}

void merge(char* s1, char* s2, int len)
{
    int s1len = (int)strlen(s1), s2len = (int)strlen(s2), i;
    for (i = 0; i < s2len - len; i++) {
        s1[i+s1len]=s2[len+i];
    }
    
}

int overlap(char* s1, char* s2)
{
    int s1last = (int)strlen(s1) - 1, s2len = (int)strlen(s2), overlap = 0, i, j;
    char suff[1000]={0}, pref[1000]={0};
    for (i = s1last, j = 1; i> 0 && j < s2len; i--, j++) {
        substring(s1, suff, i, (int)strlen(s1));
        substring(s2, pref, 0, j);
        if (strcmp(suff, pref) == 0)
            overlap = j;
        
    }
    return overlap;
}

void superString(int n, int amount)
{
    int i, j, maxoverlap = 0, currentoverlap = 0, im=0, jm=0;
    if (amount == 1)
    {
        for (i=0; i < n; i++)
        {
            if (used[i] == 0){
                answer = (int)strlen(strtemp[i]);
                break;
            }
            
        }
    }
    else
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++) {
                if ((i != j) && (used[i] != 1) && (used[j] != 1) ) {
                    currentoverlap = overlap(strtemp[i], strtemp[j]);
                    if (currentoverlap >= maxoverlap) {
                        maxoverlap = currentoverlap;
                        im =i;
                        jm = j;
                    }
                }
            }
        }
        merge(strtemp[im], strtemp[jm], maxoverlap);
        used[jm] = 1;
        superString(n, amount-1);
        
    }
}


int main(int argc, const char * argv[]) {
    int n, i;
    scanf("%d", &n);
    
    for (i=0; i<n; i++) {
        gets(a[i]);
        strtemp[i] = a[i];
        used[i] = 0;
    }
    superString(n,n);
    printf("%d\n", answer);
   
    return 0;
}
