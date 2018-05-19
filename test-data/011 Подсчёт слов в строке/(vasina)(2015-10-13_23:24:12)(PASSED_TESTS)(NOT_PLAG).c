
#include <stdio.h>
 
int main()
{
    char s[100];
    gets(s);
    printf("%d\n", wcount(s));
}
   
   
int wcount(char *s)
{
        int i, k=0, l;

	l=strlen(s);

	for (i= 0; i < l; i++)	
	if (s[i] == ' ' && i+1 < l && s[i+1] != ' ') k++;	
		
	if (s[0] != ' ' && l>0 ) k++;

	return k;
}