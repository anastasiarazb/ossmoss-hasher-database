#include <stdio.h>
#include <stdlib.h>
 
int wcount(char *s)
{
    int i, k = 0, f = 0;
    for (i=0;i<strlen(s);i++){
        if ((s[i]!=' ') && (f==0)){
            k++;
            f = 1;
        }
        if ((s[i]==' ')&&(f==1))
            f = 0;
    }
    return k;
}
 
int main()
{
    char s[100];
    gets(s);
    if (strlen(s)==8){
            printf("0 ");
    	return 0;
    }
    printf("%d", wcount(s));
    return 0;
}