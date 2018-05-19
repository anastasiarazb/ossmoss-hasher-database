#include <stdio.h>
int C[10],minx,n;
int B[10][10];
char* A[10];
int min(int a,int b) {
    if (a>b)
        return b;
    else
        return a;
}

int get (char* a, char* b) {
    int i;
    int k=min(strlen(a),strlen(b));
        int j=k+1;
    for (i=k;(i>0) && (i!=j);i--) {
        for (j=0;j<i && b[j]==a[strlen(a)-i+j];j++) {
        }
    }    
    return strlen(b)-i;
    
}


int rec(int k, int a) {
    C[k]=a;
    int i;
    if (k==(n-1)) {
        int S=0;
        for (i=0;i<(n-1);i++) {
            S+=B[C[i]][C[i+1]];
        }
        S+=strlen(A[C[0]]);
        if ((minx==-1) || (S<minx)) {
            minx=S;
        }
        return 0;
    }
    for (i=0;i<n;i++) {
        int j;
        for (j=0;j<=k && C[j]!=i;j++) {
        }
        if (j>k) {
            rec(k+1,i);
        }
    }
}

int main(void)
{
    int i,j;
    scanf("%d ",&n);
    for (i=0;i<n;i++) {
        A[i]=malloc(255*sizeof(char));
        gets(A[i]);
    }
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            if (i!=j) 
                B[i][j]=get(A[i],A[j]);
        }
    }
    minx=-1;
    for (i=0;i<n;i++) {
        rec(0,i);
    }
    for (i=0;i<n;i++) {
        free(A[i]);
    }
    printf("%d",minx);
    return 0;
}
