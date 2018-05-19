#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int compare(const void * x1, const void * x2){
    return ( *(int*)x1 - *(int*)x2 );
}
int maxarray(int *array, int n){
    int i,max=array[0];
    for(i=0;i<n;i++) if(array[i]>max) max=array[i];
    return max;
}
int Intersection(char *a, char *b){
    //printf("Intersection!\n");
    int i,j,lengtha,lengthb,len=0,len1=0,len3=0;
    lengtha=strlen(a);
    lengthb=strlen(b);
    //printf("%s %s\n",a ,b);
    //printf(" %d %d \n",lengtha,lengthb);
    if(strcmp(a,b)==0) return 0;
    else{
        i=lengtha-1;
        int k=0;
        int z=lengtha-1;
        for(j=0;j<lengtha;j++){
            if((a[i]==b[k])&&(i<=lengtha-1)){
                while((a[i]==b[k])&&(i<=lengtha-1)){
                    len++;
                    k++;
                    i++;
                }
            }
            if((i==lengtha)&&(len>len1)) len1=len;
            len=0;
            k=0;
            z--;
            i=z;
        }
    //printf("len=%d\n",len1);
    return len1;
    }
}
int main(){
    int n,i,j,k;
    scanf("%d\n",&n);
    char array[n][50];
    int Matrix[n][n];
    for(i=0;i<n;i++) gets(array[i]);
    for(i=0;i<n;i++) for(j=0;j<n;j++) Matrix[i][j]=Intersection(array[j],array[i]);
    /*for(i=0;i<n;i++){
       for(j=0;j<n;j++){
            printf("%d ",Matrix[i][j]);
        }
        printf("\n");
    }*/
    int FullLength=0;
    for(i=0;i<n;i++) FullLength+=strlen(array[i]);
    //printf("FullLength=%d\n",FullLength);
    int Maximums[n];
    for(i=0;i<n;i++) Maximums[i]=maxarray(Matrix[i],n);
    //for(i=0;i<n;i++) printf("%d ",Maximums[i]);
    //printf("\n");
    qsort(Maximums,n,sizeof(int),compare);
    //for(i=0;i<n;i++) printf("%d ",Maximums[i]);
    //printf("\n");
    int Minus=0;
    for(i=n-1;i>0;i--) Minus+=Maximums[i];
    //printf("Minus=%d\n",Minus);
    printf("%d\n",FullLength-Minus);
    return 0;
}



