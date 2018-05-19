#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int wcount (char *s)
{
        int in_word = 0, count_of_word = 0, i = 0;
        while (1){
                if (s[i] == '\0') break;
                        if (s[i] == ' '){
                                if (in_word == 0) i++;
                                else {
                                        in_word = 0;
	                                i++;
                                }
                        }else if (in_word == 0){
                                count_of_word++;
                                in_word = 1;
                                i++;
                                 }else i++;
        }
        return count_of_word;
}
int main ()
{
        char array[1000];
        gets(array);
        printf("%d", wcount(array));
}