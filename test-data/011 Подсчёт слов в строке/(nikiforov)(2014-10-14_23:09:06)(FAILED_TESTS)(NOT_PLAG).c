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
    
    char string[100];
//    string=(char*)malloc(n*sizeof(char));
    
    strncpy(string, s, n);
//    printf("string = %s\n", string);
    
    if (n==0) {
//        free(string);
        return 0;
    }
    
    if ((n==1)&&(string[0]!=' ')){
//        free(string);
        return 1;
    }
    
    if (string[0]!=' ') {
        sum+=1;
    }

    
    for (i=1; i<n; i++) {
        if ((string[i]!= ' ')&&(string[i-1]== ' '))
            sum+=1;
//        if(s[i]!=0) printf("%s -> %d\n", &s[i], sum);
    }
    
    if (sum!=0){
//        free(string);
        return sum;
    }else{
        for (i=0; i<n; i++) {
            if (string[i]!= ' ') a+=1;
        }
        if (a!=0){
//            free(string);
            return 1;
        }
    }
//    free(string);
    return sum;
}
//    jg foh uiwduiwwi  wodg y di wuy du wi 
int main(int argc, const char * argv[]) {
    

    char s;
    
    gets(&s);
    
    int n =wcount(&s);
    
    printf("%d", n);
    
 //   int *d = wcount(&s);
    
 //   free(d);
    
    return 0;
}
