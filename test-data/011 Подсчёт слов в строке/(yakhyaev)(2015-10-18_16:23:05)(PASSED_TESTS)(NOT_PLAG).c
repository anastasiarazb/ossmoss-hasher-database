#include <stdio.h>
#include <string.h>
int wcount(char *s);

int main(void)
{
    char *str = malloc (sizeof(char)*1000) ;
    gets(str);
    printf("%d", wcount(str));
    free(str);
    return 0;
}
int wcount(char *s){
    int i;
    int t = 0;
    int n = strlen(s);
    for(i = 0;i < n;i++){
        if(s[i] != ' '){
          while(s[i] != ' ' && i < n){
              i++;
          }
          t++;
        }

        }

    return t;
}