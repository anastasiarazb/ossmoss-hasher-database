

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int n=0,i=1,j,k=1,m;
    char s[100];
    gets(s);
    while (s[n] != '\0')
        n++;
    char *s1=(char*)malloc((n/2+1)*sizeof(char));
    char *s2=(char*)malloc((n/2+1)*sizeof(char));
    while (k==1 && i<=(n/2)) {
        k=0;
        for (m=0;m<i;m++) {
            s1[m]=s[m];
            s1[m+1]='\0';
        }
        for (j=1;j<n/i;j++) {
            for (m=0;m<i;m++)
                s2[m]=s[j*i+m];
            s2[m+1]='\0';
            if (strcmp(s1,s2) != 0)
                k=1;
        }
        if (k == 1)
            i++;
    }
    if (k == 0)
        printf("yes");
    else printf("no");
    free(s2);
    free(s1);
    return 0;
}