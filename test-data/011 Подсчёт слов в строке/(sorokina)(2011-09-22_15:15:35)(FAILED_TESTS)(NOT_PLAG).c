#include <stdio.h>
#include <string.h>

int wcount(char *s) {
  /*в переменной n будем хранить количество букв в слове*/
  int n=0,k=0,i;
  
  for (i=0; i<strnlen(s,100); i+=1) {
  /*проверяем, яляется знак пробелом или нет*/  
    if (s[i]==' ') {
      if (n!=0) {
        k=k+1;
      }
      n=0;
    }
    else {
      n=n+1; 
      if (i==strnlen(s,100)-1) {k=k+1;}
    }
  }
  return k;
}

int main(int argc, char **argv)
{  
  char s[100];
  gets(s); 
  printf("%d\n", wcount(s)); 
  return 0;
}