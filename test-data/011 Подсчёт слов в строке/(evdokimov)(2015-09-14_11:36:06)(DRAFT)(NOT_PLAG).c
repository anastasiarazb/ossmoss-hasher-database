
#include <stdio.h>
#include <string.h>

int wcount(char *sp)
{
    int k=0;
    while (sp!=0)
    {
        sp=strtok(0," ");
        k++;
    }
    return k;
}

int main(int argc, const char * argv[]) {
    const int m = 1000;
    char str[m];
    char *sp;
    
    gets(str);
    sp=strtok(str," ");
    
    printf("%d", wcount(sp));
    return 0;
}

