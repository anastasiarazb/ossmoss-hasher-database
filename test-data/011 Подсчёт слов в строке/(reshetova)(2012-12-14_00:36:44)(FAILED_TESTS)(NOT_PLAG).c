#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int wcount (char *a)
{
    int i, number=0, temp;
    for(i=0; a[i]!=0; i++)
    {
        while (a[i]==' '&&a[i]!=0)
        {
            i++;
        }
        temp=i;
        while (a[i]!=' '&&a[i]!=0)
        {
            i++;
        }
        if (temp!=i)
        {
            number++;
        }
    }
return number;
}

int main()
{
    int i;
    char *string = (char*)malloc(100);
    gets(string);
    i=wcount(string);
    free(string);
    printf("%d\n",i);
    return 0;
}