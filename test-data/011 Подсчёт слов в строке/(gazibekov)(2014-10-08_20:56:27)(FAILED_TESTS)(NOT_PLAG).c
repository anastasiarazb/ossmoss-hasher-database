//
//  подсчет слов.c
//  
//
//  Created by MacBook return 0; on 07.10.14.
//
//

#include <stdio.h>
#include <string.h>

int wcount(char *s)
{
    int i, count = 0;
    int len=strlen(s);
    for (i=0; i<len; i++) {
        if (s[i]!=' '){
            count++;
            do i++; while ((s[i]!=' ') || (s[i]!='\0') || (s[i]!='\t'));
        }
    }
    return count;
}
    
int main()
{
    int q;
    char s[100];
    gets(s);
    q=wcount(s);
    printf("%d\n", q);
    return 0;
}
