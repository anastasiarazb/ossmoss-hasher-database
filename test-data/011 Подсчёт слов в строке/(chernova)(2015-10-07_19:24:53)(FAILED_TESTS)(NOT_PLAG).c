#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//подсчет слов в строке

int wcount(char *s);

int main(int argc, char **argv)
{
    char stroka[10000];
    gets (stroka);
    int n = 0;
    n = wcount(stroka);
    printf("%d\n", n);
}

int wcount(char *s)
 {
     int i = 0, count =0;
     unsigned long size = 0;
     size = strlen(s);
     
     while (i < size) {
         if ((s[i] >= 'a') && (s[i]<= 'z'))
         {
             while (s[i] != ' ') i++;
             count++;
         }
         else i++;
     }
     return count;
 }