#include <stdio.h>
#include <stdlib.h>

int wcount(char *s)
{
    unsigned int i, k = 0, f = 0;
    if (strlen(s)==0)
            
    	return k;
    
    for (i=0;i<strlen(s)-1;i++){
        if ((s[i]!=' ') && (f==0)){
            k++;
            f = 1;
        }
        if ((s[i]==' ')&&(f==1))
            f = 0;
    }
    //if ((int)s[99]==32)
    //    k--;
    return k;
}

int main()
{
    char s[100];
    //memset(s,(char)32,100);
    gets(s);
    /*if (strlen(s)==8){
    	printf("0 ");
    	return 0;
    }*/
    //printf("%d\t",strlen(s));
    printf("%d", wcount(s));
    return 0;
}
