#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int Intersection(char *a, char *b){
    int i,j,lengtha,lengthb,len=0,len1=0,len3=0;
    lengtha=strlen(a);
    lengthb=strlen(b);
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
    return len1;
    }
}
int main(){
    int n,i,j,k;
    scanf("%d\n",&n);
    char array[n][50];
    int Matrix[n][n];
    for(i=0;i<n;i++) gets(array[i]);
    printf("\n");
    for(i=0;i<n;i++) for(j=0;j<n;j++) Matrix[i][j]=Intersection(array[j],array[i]);
    int FullLength=0;
    for(i=0;i<n;i++) FullLength+=strlen(array[i]);
    for(i=0;i<n;i++){
        int MEMi,MEMj,k;
        int d,s;
        int max=Matrix[0][0];
        for (d=0;d<n;d++) for (s=0;s<n;s++) if (Matrix[d][s] > max){
            max = Matrix[d][s];
            MEMi=d;
            MEMj=s;
        }
        for(k=0;k<n;k++) Matrix[k][MEMj]=0;
        for(k=0;k<n;k++) Matrix[MEMi][k]=0;
        if(i!=n-1){ FullLength-=max; }
        max=0;
    }
    printf("%d\n",FullLength);
    return 0;
}



