//
//  main.c
//  SUPERPUPERSTROKA
//
//  Created by Roman on 03.11.14.
//  Copyright (c) 2014 Roman. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int overlap(char* a, char* b);
int max(int a, int b){
    if(a>b)
        return a;
    return b;
}
int overlap(char* a, char* b){
    int i, j=0, count=0;
    if((strlen(a)==0)||(strlen(b)==0))
        return 0;
    i = 0;
    while(b[i]!='\0'){
        if(a[j]==b[i]){
            count++;
            j++;
        }
        else{
            i = i-count;
            count = 0;
            j = 0;
        }
        i++;
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    unsigned long i, j, k, m, max = 0, index1=0, index2=0, super = 0, len1=0, len2=0, over=0;
    int n;
    scanf("%d\n", &n);
    unsigned long a[n];
    char strings[n][100];
    for(i = 0; i < n; i++){
        fgets(strings[i], 100, stdin);
        //gets(strings[i]);
        strings[i][strlen(strings[i])-1] = '\0';
    }
    for(i = 0; i<n; i++)
        a[i] = strlen(strings[i]);
    for(m = 0; m<n; m++){
        for(j = 0; j<n-1; j++){
            for(k = j+1; k<n; k++){
                if (overlap(strings[j], strings[k]) > max){
                    max = overlap(strings[j], strings[k]);
                    index1 = k;
                    index2 = j;
                    len1 = strlen(strings[k]);
                    len2 = strlen(strings[j]);
                }
                if (overlap(strings[k], strings[j]) > max){
                    max = overlap(strings[k], strings[j]);
                    index1 = j;
                    index2 = k;
                    len1 = strlen(strings[j]);
                    len2 = strlen(strings[k]);
                }
            }
        }
        if(max>0){
            over = max;
            for (i = len1; i<len1+len2-over; i++)
                strings[index1][i] = strings[index2][max++];
            strings[index2][0] = '\0';
            strings[index1][len1+len2-over+1]='\0';
            a[index1] = len1+len2-over;
            a[index2] = 0;
        }
        max = 0;
    }
    for(i = 0; i < n; i++){
        super +=a[i];
        
    }
    //strings[super][strlen(strings[super])-1] = '\0';
    printf("%lu\n", super);
    return 0;
}
