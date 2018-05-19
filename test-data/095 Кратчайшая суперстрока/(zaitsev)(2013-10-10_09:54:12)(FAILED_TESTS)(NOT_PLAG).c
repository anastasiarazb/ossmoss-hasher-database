#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    char* str;
    int size;
} string;

int best = INT_MAX;

int calculatePosition(char* str, char* str2) {
    int i=0,count=0;
    while (str[count]) {
        while (str[count+i]==str2[i]) {
            i++;
            if (str[count+i]=='\0') return count;
        }
        i=0;
        count++;
    }
    return count;
}


void rec(string* strs, int count,char* str,int size) {

    int i;
    char flag = 0;
    for (i=0; i<count; i++) {
        if (strs[i].str) {
            flag = 1;
            int position = calculatePosition(str,strs[i].str);
            strcpy(str+sizeof(char)*position,strs[i].str);
            char* temp_str = strs[i].str;
            strs[i].str = NULL;
            rec(strs,count,str,position+strs[i].size);
            strs[i].str = temp_str;
            str[size]='\0';
        }
    }
    if (!flag) {
        if (best>size) best=size;
    }
    
}


int main() {
    int count,i;
    scanf("%d ",&count);
    string* strs = (string*) malloc(sizeof(string)*count);
    for (i=0;i<count;i++) {
        strs[i].str = (char*) malloc(sizeof(char)*256);

        scanf("%s",strs[i].str);
        strs[i].size = (int) strlen(strs[i].str);
    }
    rec(strs,count,calloc(sizeof(char), 256*count+1),0);
    printf("%d",best);
    return 0;
}