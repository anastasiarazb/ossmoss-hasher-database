#include <stdio.h>
#include <stdlib.h>

int wcount(char *s)
{
 int i, sum, p;
    sum = 0;
    p = 0;
    i = 0;
    while (s[i] != 0){
    if (s[i] != ' ' && s[i + 1] == ' '){
        p =  1;
    }
    i++;
    if (p != 0 && s[i] == ' ' && s[i + 1] != ' ' && s[i + 1] != 0){
        sum += 1;
        p = 0;
    }
    }
if (sum == 0) return(sum);
return(sum + 1);
}

int main()
{
    char s[100];
    int t;
    gets(s);
    printf("%u", wcount(s));
    return 0;
}
