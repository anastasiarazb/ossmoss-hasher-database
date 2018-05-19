#include <stdio.h>
#include <string.h>
int wcount( char *str, int *p)
{
        int i;
        int b=0;
        if (str[1]!=' ')
        {
                for(i=0;i<p;i++)
                {
                        if (str[i]==" " && str[i-1]!= " ")
                                b++;
                }
        }
        else
        {
                if (str[1]!=" " && str[p]!=0)
                {
                        b=1;
                        for(i=0;i<p;i++)
                        {
	                        if (str[i]==" " && str[i+1]!= " ")
	                        b++;
	                }
                }
                else
                {
	                for(i=0;i<p;i++)
	                {
	                        if (str[i]==" " && str[i+1]!= " ")
	                                b++;
	                }
                }
        }
        return b;
}
int main(int argc , char ** argv)
{
        char string[1000];
        int i,k;
        gets(string);
        k=strnlen(string, 1000);
        printf("%d\n", wcount(string[1000], k));
        return 0;
}