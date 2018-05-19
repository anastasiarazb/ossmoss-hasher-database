#include <stdio.h>
#include <string.h>
int wcount(char *s)
 {
  int a=0,i=0;
     while (s[i] != 0)
         {
            if ((s[i] != ' ' && s[i+1]==' ') || (s[i] != ' ' && s[i+1]==0))
                 a++;
            i++;
         }
     printf("%d\n",a);
     return 0;
 }
main()
 {
  char p[100];
     printf("Введите строку слов\n");
     gets(p);
     wcount(p);
     return 0;
 }