#include<stdlib.h>
#include<stdio.h>
#include<string.h>
char **array;
int *count;
int result=0;
int *cnt;
int **ar;

char *ConcatStr(char *a, char *b){
    int length1=strlen(a),length2=strlen(b);
    int i,j,k,len=0,len1=0;
    i=length1-1;
    int z=length1-1;
    k=0;
    int lengthNEW=length1+length2-len1;
    char *c=(char*)malloc(lengthNEW+1);
    for(i=0;i<lengthNEW+1;i++) c[i]=0;
    *c='\0';
    for(j=0;j<length1;j++){
        if((a[i]==b[k])&&(i<=length1-1)){
            while((a[i]==b[k])&&(i<=length1-1)){
                len++;
                k++;
                i++;
            }
        }
        if(len>len1) len1=len;
        len=0;
        k=0;
        z--;
        i=z;
    }
    for(i=0;i<length1;i++) c[i]=a[i];
    int len3=length2-len1;
    for(i=0;i<len3;i++) c[length1+i]=b[len1+i];
    return c;
}
void permut(char **array, char *tek, int n, int test, int *count){
    int i,j,length;
    length=strlen(tek);
    char tek2[100];
    char cc[1000];
    strcpy(tek2,tek);
    if(test==n) if((length<result)||(result==0)) {
            //printf("result=%s -- %d\n",tek,length);
            result=length;
    }
    for(i=0;i<n;i++){
        if(count[i]==0){
            count[i]=1;
            strcpy(cc,ConcatStr(tek2,array[i]));
            free(ConcatStr(tek2,array[i]));
            permut(array,cc, n, test+1, count);
            count[i]=0;
        }
    }
}
int main(){
    int n,i,j,k;
    scanf("%d\n",&n);
    array=malloc(n);
    for(i=0;i<n;i++) {
        array[i]=(char*)malloc(11);
        gets(array[i]);
    }
    char first[1];
    first[0]='\0';
    count = (int*)malloc(n * sizeof(int));
    for(i=0;i<n;i++) count[i]=0;
    permut(array,first,n,0,count);
    printf("%d\n",result);
    return 0;
}