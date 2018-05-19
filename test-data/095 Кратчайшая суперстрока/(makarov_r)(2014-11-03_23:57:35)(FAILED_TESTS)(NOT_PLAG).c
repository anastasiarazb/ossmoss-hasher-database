//
//  main.c
//  SUPERPUPERSTROKA
//
//  Created by Roman on 03.11.14.
//  Copyright (c) 2014 Roman. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int max(int a, int b){
    if(a>b)
        return a;
    return b;
}
int prefix_suffix(char* a, char* b){
    int i, j, count=0, temp = 0, r=1;
    for(i = 0; i< strlen(a)-1; i++){
        for(j = temp; j<strlen(b); j++){
            if (a[i] == b[j]){
                count++;
                temp = j+1;
                break;
            }
            else if((a[i+1]=='\n')||(b[j+1]=='\n')){
                count = 0;
                temp = 0;
                i = r;
                r++;
            }
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    int n, i, temp = 0, c, j, temp1, temp2;
    unsigned long super = 0;
    scanf("%d\n", &n);
    char strings[n][100];
    for(i = 0; i < n; i++){
        fgets(strings[i], 100, stdin);
        //strings[i][strlen(strings[i])-1]= '\0';
    }
    for(i = n-1; i>0; i--){
        c += i;
    }
    for(i = 0; i<n; i++){
        super += strlen(strings[i]);
    }
    super -= n;
    int pref[2*c][3];
    for(i = 0; i<n-1; i++){
        for (j = i+1; j < n; j++){
            pref[temp][0] = prefix_suffix(strings[i], strings[j]);
            pref[temp][1] = i;
            pref[temp][2] = j;
            temp++;
            pref[temp][0] = prefix_suffix(strings[j], strings[i]);
            pref[temp][1] = j;
            pref[temp][2] = i;
            if(pref[temp][0]==pref[temp-1][0])
                pref[temp][0] = 0;
            temp++;
        }
    }
    for(i = 0; i<n-1; i++){
        for(j = i+1; j<n; j++){
            if(pref[i][1] == pref[j][1]){
                pref[i][0] = max(pref[i][0], pref[j][0]);
                pref[j][0] = 0;
            }
        }
    }
    for(i = 0; i<n-1; i++){
        for(j = i+1; j<n; j++){
            if(pref[i][2] == pref[j][2]){
                pref[i][0] = max(pref[i][0], pref[j][0]);
                pref[j][0] = 0;
                
            }
        }
    }
    for(i = 0; i<2*c; i++){
        for(j = 0; j<2*c; j++){
            if(pref[i][0]>pref[j][0]){
                temp = pref[i][0];
                temp1 = pref[i][1];
                temp2 = pref[i][2];
                pref[i][0] = pref[j][0];
                pref[i][1] = pref[j][1];
                pref[i][2] = pref[j][2];
                pref[j][0] = temp;
                pref[j][1] = temp1;
                pref[j][2] = temp2;
            }
        }
    }
    for(i = 0; i<n-1; i++){
        super-=pref[i][0];
    }
    printf("%ld\n", super);
    return 0;
}
