//
//  main.c
//  14
//
//  Created by Никифоров Иван on 14.10.14.
//  Copyright (c) 2014 NIkif. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int wcount(char *s)
{
    int n, i, sum=0, a=0;
    
    n = (int)strlen(s);
//    printf("n = %d\n", n);
    
    if (n==0) {
        return 0;
    }
    
    if ((n==1)&&(s[0]!=' ')){
        return 1;
    }
    
    if (s[0]!=' ') {
        sum+=1;
    }

    
    for (i=1; i<n; i++) {
        if ((s[i]!= ' ')&&(s[i-1]== ' '))
            sum+=1;
//        if(s[i]!=0) printf("%s -> %d\n", &s[i], sum);
    }
    
    if (sum!=0){
        return sum;
    }else{
        for (i=0; i<n; i++) {
            if (s[i]!= ' ') a+=1;
        }
        if (a!=0){
            return 1;
        }
    }
    return sum;
}


//    jg foh uiwduiwwi  wodg y di wuy du wi


int main(int argc, const char * argv[]) {
    

    char s[500];
    
    gets(s);
    
    printf("%d", wcount(s));
    
    return 0;
}
