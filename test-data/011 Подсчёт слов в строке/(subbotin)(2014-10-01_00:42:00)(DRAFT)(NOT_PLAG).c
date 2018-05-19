#include <stdio.h>
#include <stdlib.h>
int wcount(char *s)
{
        int n=0,i;
        if(s[0]!= ' ') ++n;
        for(i=0;s[i];i++) if(s[i] == ' ' && s[i+1] != ' ' && s[i+1] != 0) ++n;
        return n;
}
  
int main(int argc, int **argv)
{
        char *a = (char*)malloc(100*sizeof(char));
        gets(a);
        printf("%d ", wcount(a));
        free(a);
        return 0;
}
