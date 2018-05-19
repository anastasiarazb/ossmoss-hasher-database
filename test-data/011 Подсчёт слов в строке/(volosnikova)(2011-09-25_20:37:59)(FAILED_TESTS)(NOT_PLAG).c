#include <stdio.h>
#include <stdlib.h>

int wcount(char *s)
{
    char *gets(char *s);
    int w = 0, k, i;

        for (i = 0, k = 0; s[i] != '\0'; ++i){

                if (s[i] == ' ')
                    w = 0;

                else if (w == 0){
                    w = 1;
                    ++k;
                }

        }
    printf("%d\n", k);
    return 0;
}

int main(int argv, char **argc)
{
    int i;
    printf("Введите размер строки и саму строку: ");
    scanf ("%d\n", &i);

    char s[i];
    gets(s);

    wcount(s);

   return 0;
}
