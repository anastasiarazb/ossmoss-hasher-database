#include <stdio.h>
#include <stdlib.h>

int k = 0;

int wcount(char *s)
{
    char *s1=(char*)s;
    int w = 0, i;

        for (i = 0; s1[i] != '\0'; ++i){

                if (s1[i] == ' ')
                    w = 0;

                else if (w == 0){
                    w = 1;
                    ++k;
                }
        }

}

int main(int argv, char **argc)
{
    int i;
    printf("Введите размер строки и саму строку: ");
    scanf ("%d\n", &i);

    char s[i];
    gets(s);

    wcount(s);

    printf("%d", k);

   return 0;
}
