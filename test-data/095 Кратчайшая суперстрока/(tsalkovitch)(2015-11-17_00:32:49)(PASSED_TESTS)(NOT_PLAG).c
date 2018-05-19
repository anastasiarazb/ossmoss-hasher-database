
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
int imposition(char * str1, char * str2){
        int l = strlen(str1), max = -1;
        for (int i = 1; i < l; i++){           
                int k = 0;
                int j = i;
                int s = 0;
                while(str1[j] && str2[k] && str1[j] == str2[k]){
                        s++;
                        j++;
                        k++;}
                if (str1[j] && str2[k])
                        s = 0;
                if (s > max)
                        max = s;}
                //printf("%d  # %d \n", max, i);}
return max;}
 
void conc(char * str1, char * str2,int  m){
        str1[strlen(str1) - m] = '\0';
        strcat(str1, str2);
        str2[0] = '\0';
}                      
               
 
int main() {
int n, res = 0;
int sec = 0;
int f = 0;
scanf("%d ", &n);
char s[n][100];
for (int i = 0; i < n; i++)//{
        scanf("%s", s[i]);
        //printf("%s \n", s[i]);}
for (int k = 1; k < n; k++){
        int max = -1;
        f = 0;
        sec = 0;
        for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                        if ((i != j) && (strlen(s[i]) != 0) && (strlen(s[j]) != 0)){
                                int sum = imposition(s[i], s[j]);
                                //printf("%d %d i =%d j =%d Problem \n", sum, max, i, j);
                                if (sum > max){
                                        max = sum;
                                        f = i;
                                        sec = j;}}}}
        //printf("%d %d %d Hell \n", f, sec, max);     
        conc(s[f], s[sec], max);
        res = strlen(s[f]);}
        //for (int i = 0; i< n; i++)
        //      printf("%s \n", s[i]);
        //printf("\n");}
printf("%d", res);
}