//
//  main.c
//  1
//
//  Created by Никифоров Иван on 16.11.14.
//  Copyright (c) 2014 NIkif. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int merge(char*, int, char*, int);

int main(int argc, const char * argv[]) {
    
    int n, i, d = 0 , j, max=0, numstroki1 = 0, numstroki2 = 0, y, dad, x = 0;
    
    scanf("%d", &n);
    
    char s[10][100], news[10][100];
    
    for (i=0; i<n; i++) {
        scanf("%s", s[i]);
    }
    
    d=merge(s[1],(int)strlen(s[1]), s[0], (int)strlen(s[0]));
    
//    printf("d= %d\n\n", d);
    //////
    for (dad=0; dad<n; dad++) {
        for (i=0; i<n; i++) {
            if (strcmp(&s[i][0], "")) {
                for (j=i+1; j<n; j++) {
                    if ((i!=j)&&(strcmp(&s[j][0], ""))) {
                        d = merge(s[j],(int)strlen(s[j]), s[i], (int)strlen(s[i]));
                        if (max<d) {
                            max=d;
                            numstroki1=j;
                            numstroki2=i;
                        }
                    //                    printf("d = %d\n", d);
                        d = merge(s[i],(int)strlen(s[i]), s[j], (int)strlen(s[j]));
                        if (max<d) {
                            max=d;
                            numstroki1=i;
                            numstroki2=j;
                        }
                    //                    printf("d = %d\n", d);
                    }
                    //            printf("при итерации номер %d %d max = %d\n", i, j, max);
                }
            }
            ///////////
        }
        
/*        printf("max = %d\n", max);
        printf("num1 = %d\n", numstroki1);
        printf("num2 = %d\n", numstroki2);*/
        
        ////////////////
        
        for (y=0; y<n; y++) {
            if (y==numstroki1) {
                strcat(s[numstroki1], &s[numstroki2][max]);
                s[numstroki2][0] = '\0';
            }
//            printf("s[%d] = %s\n", y, s[y]);
        }
        
        max = 0;
        
/*        for (i=0; i<n; i++) {
            printf("s[%d] = %s\n", i, s[i]);
        } */
    }
    for (i=0; i<n; i++) {
        x+=strlen(s[i]);
    }
   
    printf("%d", x);
    
    return 0;
}

int merge(char *a, int d1, char *b, int d2)
{
    int k=0, i, j, help;
    
    char a1[d1], b1[d2];
    
    strcpy(a1, a);
    strcpy(b1, b);
    
    help=d1;
    
    for (j=1; j<d1+1; j++) {
/*        printf("сначала s = %s\n", a1);
        printf("j = %d\n", j);
        printf("help = %d\n", help); */
        
        for (i=0; i<help; i++) {
            if (memcmp(&a1[i], &b1[i], 1)==0) {
                k++;
//                printf("%d+\n", i);
            }else{
                k=0;
                strcpy(a1, &a[j]);
//                printf("else%d\n", i);
                break;
            }
        }
        if (i==help) {
//            printf("break\n");
            break;
        }
        help = (int)strlen(a1);
//        printf("вконце s = %s\n", a1);
        /*        printf("j = %d\n", j);
         printf("s = %s\n", a1);
         printf("%d\n", (int)strlen(a1));*/
    }
    
    return k;
}
