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
    int i, j, k, m, max = 0, index1=0, index2=0, super = 0;
    int n;
    scanf("%d\n", &n);
    char strings[n][100];
    for(i = 0; i < n; i++){
        fgets(strings[i], 100, stdin);
        //gets(strings[i]);
        strings[i][strlen(strings[i])-1] = '\0';
    }
    for(m = 0; m<n; m++){
        for(j = 0; j<n-1; j++){
            for(k = j+1; k<n; k++){
                if (overlap(strings[j], strings[k]) > max){
                    max = overlap(strings[j], strings[k]);
                    index1 = k;
                    index2 = j;
                }
                if (overlap(strings[k], strings[j]) > max){
                    max = overlap(strings[k], strings[j]);
                    index1 = j;
                    index2 = k;
                }
            }
        }
        if(max>0){
            for (i = strlen(strings[index1]); i<(strlen(strings[index1])+strlen(strings[index2])-overlap(strings[index1], strings[index2])); i++)
                strings[index1][i] = strings[index2][max++];
            strings[index2][0] = '\0';
        }
        max = 0;
    }
    for(i = 0; i < n; i++){
        if(strlen(strings[i])!=0)
            super +=strlen(strings[i]);
            
    }
    //strings[super][strlen(strings[super])-1] = '\0';
    printf("%lu\n", super-1);
    return 0;
}
