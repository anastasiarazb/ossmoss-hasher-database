#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount (char *S)
{
int i, number_of_words=0, beginning_of_word;
for(i=0; S[i]!=0; i++)
{
while (S[i]==' '&&S[i]!=0)
{
i++;
}

beginning_of_word=i;

while (S[i]!=' '&&S[i]!=0)
{
i++;
}

if (beginning_of_word!=i)
{
number_of_words++;
}

}
return number_of_words;
}

int main(void)
{
char *string = (char*)malloc(100);
fgets(string, sizeof(string), stdin);
printf("%d", wcount(string));
free(string);
return 0;
}