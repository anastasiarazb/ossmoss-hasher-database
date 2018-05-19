#include <stdio.h>

int main(int argc , char ** argv)
{
char s[255];
gets(s);
unsigned int word, i;
word=0;
for (i=0;i<strlen(s)-1;i++)
 if ((s[i]==' ') && (s[i+1]!=' '))
  word++;
if (s[0]!=' ')
    word++;
printf("%c", word);
}