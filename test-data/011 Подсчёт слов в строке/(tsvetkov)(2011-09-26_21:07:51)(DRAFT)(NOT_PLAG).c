#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
    int konets,nw,i;

    nw=konets=0;
    for (i=0; i<strlen(s); i+=1)
    {
        if (s[i]==' ')
        {

                if (konets!=0)
                nw++;

            konets=0;
        }
        else
        {
            konets++;
            if (i==strlen(s)-1) nw++;;
        }
    }
  return nw;
}

int main()
{
  char s1[100];
  gets(s1);
  printf("%d", wcount(s1));
  return 0;
}         