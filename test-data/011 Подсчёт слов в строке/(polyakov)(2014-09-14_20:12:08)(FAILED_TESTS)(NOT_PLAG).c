// Подсчет слов в строке. Задача 14.

#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>

  int main(int argc , char ** argv)
{
    char mass1[1000];
    int i, word;
    gets(mass1);
    word = 0;
    for (i = 1; i <= strlen(mass1); i++)
    {
        if (mass1[i] == ' ')
        {
            word = word + 1;
        }
    }
    printf("%d", word + 1);
}
int wordcount(char *S)
{
    int i, word = 0;
    for (i = 1; i <= strlen(S); i++)

    {
        if (S[i] == ' ')
        {
            word=word+1;
        }
    }
    return 0;
}