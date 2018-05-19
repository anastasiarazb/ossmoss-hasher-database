/*
Если строку s можно представить в виде ddddd где d - некая подстрока,
то длина строки s обязана делиться на длину строки d.
В массив s я записываю исходную строку
В массив smal записываем первые i символов строки s, если длина s делится на i.
В массив snext записываем последующие i символов и проверяем, равняются ли smal и snext.
Если все snext равны smal то строка является периодической.
 */
#include <stdio.h>
#include <string.h>

int main()
{
  int max = 1000,i,j,c,n,yes = 1,no = 0;
  char s[max],smal[max],snext[max];
    
  gets(s);
  
  n = strnlen(s,max);
  
  
  for (i = 1;i < n;i++)
  {
    if (n % i == 0)
    {
      strncpy(smal,s,i);
      smal[i] = 0;
      c = yes; /*предполагаем что строка периодична а затем ищем противоречие*/
      for (j = 0;j < n / i;j++)
      {
        strncpy(snext,s + j*i,i);
	snext[i] = 0;
	if (strcmp(smal,snext) != 0) 
	{
	  c = no;
	  break;
	}
      }
      if (c == yes) break;
    }
  }
  
  if (c == yes) printf("yes\n");
  else printf("no\n");
  
  return 0;
}