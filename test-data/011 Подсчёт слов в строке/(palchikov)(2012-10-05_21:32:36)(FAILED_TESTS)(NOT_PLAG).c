#include <stdio.h>
#include <string.h>

int wcount(char *s) 
{ 
       int i, res = 0, flag = 0;
       for(i=0;i<strlen(s);i++){
               if(s[i] != ' ' && (i == strlen(s)-1 || s[i+1] == ' ')) res++;
       }
       return res;
} 

int main()
{
        char str[100];
        gets(str);
        printf("%d\n", wcount(str));
    return 0;
}