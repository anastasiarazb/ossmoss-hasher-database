#include <stdio.h>
#include <string.h>
int wcount( char *string, int k)
{
    int i;
    int b=0;
    for(i=1;i<k;i++)
    {
        if ((string[i]==" ") && (string[i-1]!= " "))
            b++;
    }
    if (string[k]!=" ")
        b++;
    
    return b;
}
int main()
{
    int k;
    char string[100];
    gets(string);
    k=strlen(string);
    printf("%d\n", wcount(string, k));
    return 0;
}