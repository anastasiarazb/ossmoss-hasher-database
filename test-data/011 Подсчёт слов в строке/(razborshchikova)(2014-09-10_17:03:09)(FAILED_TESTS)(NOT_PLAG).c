#include <stdio.h>

#define MAX_LEN 100   //Максимальная длина считываемой строки

int wcount(char*);

int main(void)
{
    char str[MAX_LEN];
    gets(str);
    printf("%d\n", wcount(str));
    return 0;
}
int wcount(char *s)
{
    int i, counter;
    counter = s[0] == ' ' ? 0 : 1; // Если первый символ не пробельный, то засчитать начало слова
    for(i = 1; s[i] != '\0'; ++i){
        if((s[i-1]== ' ') && (s[i]!= ' ')) ++counter;
        //Подсчитывает, сколько существует начал слов, т.е.
        //Сколько раз было сочетание "пробел-буква"
    }
    return counter;
}