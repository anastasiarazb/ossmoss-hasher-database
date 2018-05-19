#include <stdio.h> 
#include <math.h> 


void main() 
{ 


char str[] = " Как в Си определить количество слов в строке? "; 
int count = 0, size, flag = 0; 
size = sizeof(str) / sizeof(char) - 1; 

for (int n = 0; n < size; n++) 
{ 
if (str[n] != ' ' && flag == 0) 
{ 
flag = 1; 
if (flag == 1) count++; 
} 
else if (str[n] != ' ' && flag == 1) continue; 
else flag = 0; 
} 

printf("\n Количество слов = %d", count); 

getch(); 
} 