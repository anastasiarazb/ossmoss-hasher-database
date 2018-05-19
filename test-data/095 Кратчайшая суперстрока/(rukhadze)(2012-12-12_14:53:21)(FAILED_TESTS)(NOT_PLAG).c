#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fac (int i){
    if (i==0)
        return 0;
    int j,q;
    q=1;
    for (j=1;j<=i;j++)
        q=q*j;
    return q;
}

char** GMP (int N){
    int i,q,j,k;
    char **d,**c;
    //c=malloc(fac(N-1)*sizeof(char*));
    //for (i=0;i<fac(N-1);i++)
    //    c[i]=malloc(100*sizeof(char));
    if (N==1){
        d=malloc(fac(N)*sizeof(char*));
         for (i=0;i<fac(N);i++)
                d[i]=malloc(50 *sizeof(char));
        d[0][0]='1';
        d[0][1]=0;
        }
    else {
        c=GMP(N-1);
        d=malloc(fac(N)*sizeof(char*));
         for (i=0;i<fac(N);i++)
                d[i]=malloc(50*sizeof(char));
        q=0;
        for (i=0;i<fac(N-1);i++)
            for (j=0;j<N;j++){
                for (k=0;k<N-1;k++){
                    if (k<j)
                        d[q][k]=c[i][k];
                    else
                        d[q][k+1]=c[i][k];
                    d[q][j]=N+'0';
                }
                q++;
            }
    }
    if (N!=1){
        for (i=0;i<fac(N-1);i++)
            free (c[i]);
        free (c);
    }
    return (d);
}

int suf (char* a, char* b){
    int i,j,k,fl;
    for (i=0;i<strnlen(a,50);i++){
        k=0;
        fl=1;
        for (j=0;a[j+i]!=0&&b[j]!=0;j++)
            if (a[j+i]==b[j])
                k++;
            else{
                fl=0;
                break;
            }
        if (fl!=0)
            return k;
    }
    return 0;
}

int main (){
    int N,i,q,**z,j,k,max,r1,r2,len;
    char **c,**w;
    scanf("%d\n",&q);
    w=malloc(q*sizeof(char*));
    for (i=0;i<q;i++)
        w[i]=malloc(50*sizeof(char));
    for (i=0;i<q;i++)
        gets (w[i]);
    z=malloc(q*sizeof(int*));
    for (i=0;i<q;i++)
        z[i]=malloc(q*sizeof(int));
    for (i=0;i<q;i++)
        for (j=0;j<q;j++)
            z[i][j]=suf(w[i],w[j]);
    //for (i=0;i<q;i++){
     //   for (j=0;j<q;j++)
         //   printf ("%d ",z[i][j]);
     //   printf ("\n");
    //}
    N=q;
    //c=malloc(fac(N)*sizeof(char*));
    //for (i=0;i<fac(N);i++)
      //  c[i]=malloc(100*sizeof(char));
    c=GMP(N);

    max=0;
    //for (i=0;i<fac(N);i++)
       // printf ("%s\n",c[i]);
    for (i=0;i<fac(N);i++){
        k=0;
        for (j=1;j<q;j++){
            r1=c[i][j-1]-'0'-1;
            r2=c[i][j]-'0'-1;
            k+=z[r1][r2];
            if (k>max)
                max=k;
            }
    }
    //printf ("=%d\n",max);
    len=0;
    for (i=0;i<q;i++)
        len+=z[i][i];
    printf ("%d\n",len-max);
    for (i=0;i<q;i++)
        free (w[i]);
    free(w);
     for (i=0;i<q;i++)
        free (z[i]);
    free(z);
    for (i=0;i<fac(q);i++)
        free (c[i]);
    free(c);
    /*gets (a);
    gets (b);
    d=suf(a,b);
    printf ("%d\n",d);*/

    return 0;
    }
