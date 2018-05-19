
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    char* str;
    int size;
    char disabled;
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


void rec(string* strs, int count,string* str,int size) {
    if (size>best) return;
    int i;
    char flag = 0;
    for (i=0; i<count; i++) {
        if (!strs[i].disabled) {
            flag = 1;
            int position = calculatePosition(str->str,strs[i].str);
            strs[i].disabled = 1;
            rec(strs,count,&strs[i],size - (str->size-position)+strs[i].size);
            strs[i].disabled = 0;
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
        strs[i].disabled = 0;
    }
    for (i=0;i<count;i++) {
        strs[i].disabled = 1;
        rec(strs, count, &strs[i],strs[i].size);
        strs[i].disabled = 0;
    }
    printf("%d",best);
    for (i=0;i<count;i++) {
        free(strs[i].str);
    }
    free(strs);
    return 0;
}