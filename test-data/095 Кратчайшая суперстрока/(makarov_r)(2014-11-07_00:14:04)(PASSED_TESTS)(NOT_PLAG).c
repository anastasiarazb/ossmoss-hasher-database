//
//  main.c
//  Sprstr
//
//  Created by Roman on 06.11.14.
//  Copyright (c) 2014 Roman. All rights reserved.
//

#include <stdio.h>
#include <string.h>
unsigned long overlap(char* a, char* b){
    unsigned long len_a = strlen(a), len_b = strlen(b);
    int i, j=0, count=0;
    if((len_a==0)||(len_b==0))
        return 0;
    i = 0;
    while(i<len_b){
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
void merge(char* a, char*b, unsigned long over){
    unsigned long i, temp = over;
    unsigned long len_a = strlen(a), len_b = strlen(b);
    for(i = len_a; i<len_a+len_b+over; i++)
        a[i] = b[temp++];
    a[strlen(a)] = '\0';
}
int main(int argc, const char * argv[]) {
    unsigned long i, n, max = 0, index1 = 0, index2 = 0, j, k, over = 0, super=0;
    scanf("%lu\n", &n);
    char s[n][100];
    char* ps[n];
    unsigned long a[n];
    for(i = 0; i< n; i++){
        fgets(s[i], 100, stdin);
        s[i][strlen(s[i])-1] = '\0';
        ps[i] = s[i];
        a[i] = strlen(s[i]);
    }
    for(i = 0; i<n; i++){
        for(j = 0; j<n-1; j++){
            for(k = j+1; k<n; k++){
                if((ps[j]!=NULL)&&(ps[k]!=NULL)){
                    over = overlap(ps[j],ps[k]);
                    if (over>max){
                        max = over;
                        index1 = k;
                        index2 = j;
                    }
                    over = overlap(ps[k],ps[j]);
                    if (over>max){
                        max = over;
                        index1 = j;
                        index2 = k;
                    }
                }
            }
        }
        if(max>0){
            merge(ps[index1], ps[index2], max);
            ps[index2] = NULL;
            max = 0;
            a[index2] = 0;
        }
    }
    for(i = 0; i<n; i++){
        if(a[i]!=0)
            super+=strlen(ps[i]);
    }
    printf("%lu", super);
    
    return 0;
}
