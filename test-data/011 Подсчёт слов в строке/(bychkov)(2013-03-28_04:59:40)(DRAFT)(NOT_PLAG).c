#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount(char *s){
    int n = 0, i, j;
    for(i = 0; i < strlen(s); i++)
          if(s[i] != ' '){
                     n++;
                     j = i + 1;
                     while(s[j] != ' ')
                             i = j;
                     j++;
          }
    return n;
}

int main()
{
    int i;
    char m1[255];
    char m2[2] = {" "};
    for(i = 0; i < 255; i++)
          m1[i]=0;
    gets(m1);
    strcat(m1,m2);
    printf("%d", wcount(m1));
    return 0;
}
