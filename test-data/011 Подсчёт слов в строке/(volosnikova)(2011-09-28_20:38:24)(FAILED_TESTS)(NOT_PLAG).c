#include <stdio.h>
#include <stdlib.h>

int wcount(char *s)
{
    char *s1=(char*)s;
    int w = 0, i,k = 0;

        for (i = 0; s1[i] != '\0'; ++i){

                if (s1[i] == ' ')
                    w = 0;

                else if (w == 0){
                    w = 1;
                    ++k;
                }
        }
return k;
}

int main(int argv, char **argc)
{
    int i,n;
    printf("Введите размер строки и саму строку: ");
    scanf ("%d\n", &i);

    char s[i];
    gets(s);

    n = wcount(s);

    printf("%d", n);

   return 0;
}
