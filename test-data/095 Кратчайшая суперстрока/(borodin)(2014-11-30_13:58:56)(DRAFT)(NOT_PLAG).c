#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long overlap(char *s1, char *s2)
{
    unsigned long i, j, result=0, k, l=0;
    unsigned long dl1=strlen(s1)-1, dl2=strlen(s2);
    for(i=dl1; i>0 && l<dl2; i--, l++)
    {
        k=i;
        for(j=1; j<=dl2 && k<=dl1; j++)
        {
            if(s1[k++]==s2[j-1])
            {
                if(j>result && s1[k]=='\0') 
                    result=j;
            }
            else 
                break;
        }
    }
    return result;
}

void merge (char *s1, char *s2, unsigned long max_ov)
{
    unsigned long l1=strlen(s1), l2=strlen(s2);
    int i;
    for (i=0; i<l2-max_ov; i++)
    {
        s1[i + l1]=s2[max_ov+i];
    }
    s1[l1+l2-max_ov]='\0';
}

int main(int argc, char** argv)
{
    int i, j, n, temp1=0, temp2=0, count_n;
    unsigned long q, max_ov=0, answer=0;
    scanf("%d\n", &n);
    count_n=n;
    int help[n];
    for(i=0; i<n; ++i)
    {
        help[i]=1;
    }
    char str[n][100];
    char *mas[n];
    for(i=0; i<n; i++)
    {
        mas[i]=str[i];
        fgets(mas[i], 100, stdin);
        *(mas[i]+strnlen(mas[i], 100)-1)='\0';
    }
    while(count_n > 1)
    {
        max_ov=0, temp1=0, temp2=0, q=0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(help[i]!=0 && help[j]!=0 && (i!=j))
                {
                    q=overlap(mas[i], mas[j]);
                    if(q>=max_ov)
                    {
                        temp1=i;
                        temp2=j;
                        max_ov=q;
                    }
                }
            }
        }
        merge(mas[temp1], mas[temp2], max_ov);
        help[temp2] = 0;
        --count_n;
    }
    for(i=0; i<n; ++i)
    {
        if(help[i]!=0) 
            answer=strlen(mas[i]);
    }
    printf("%ld\n", answer);
    return 0;
}