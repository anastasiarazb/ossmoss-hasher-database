//
//  main.c
//  cccC
//
//  Created by Imprezo on 03.11.14.
//  Copyright (c) 2014 Imprezo. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int compare(char *p1,char *p2)
{
    int in=0,i=0,j=0;
    unsigned long LenP1=strlen(p1);
    for (i=0;i<LenP1;i++)
    {
        if (p1[i]==p2[j])
        {
            in=1;
            j++;
        }
        else
        {
            if(in==1)
            {
                in=0;
                i=i-j;
                j=0;
            }
        }
    }
    return j;
}

int main(int argc, char **argv)
{
    int n,i,j,k,f,StrLen=0;
    scanf("%d ", &n);
    char strs[n][100];
    for (i = 0; i < n; i++)
    {
        gets(strs[i]);
        StrLen+=strlen(strs[i]);
    }
    int SupStr[n][n],Max=0,MaxMas[n],jmax,kmax,Min=99999;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            SupStr[i][j]=compare(strs[i],strs[j]);
            if (i==j) SupStr[i][j]=0;
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            for (k=0;k<n;k++)
            {
                if(SupStr[j][k]>Max)
                {
                    jmax=j;
                    kmax=k;
                    Max=SupStr[j][k];
                }
            }
        }
        for (f=0;f<n;f++)
        {
            SupStr[f][kmax]=0;
            SupStr[jmax][f]=0;
        }
        MaxMas[i]=Max;
        Max=0;
    }
    for(i=0;i<n;i++)
    {
        Max += MaxMas[i];
        if(MaxMas[i] < Min)
            Min = MaxMas[i];
    }
    Max-=Min;
    printf("%d\n",StrLen-Max);
    return 0;
}