#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int overlap(char *str1, char *str2)
{
    int j, i, len1 = strlen(str1), len2 = strlen(str2), over = 0, eq = 0;
    
    for(i = 1;i < len1;i++){
        j = i;
        while((j < len1) && (eq < len2)){
           if(str1[j] == str2[eq]){
               ++eq; 
	       ++j;
	   }else{  
	       eq = 0;
	       break;
	   }
	
	if(eq > over) over = eq;   
        } 
    }
     return over;
}

void concat(char *str1, char *str2, int over)
{
    str1[strlen(str1) - over] = '\0';
    strcat(str1, str2);
    str2[0] = '*';
}

int main()
{
    int n, i, j;
    scanf("%d ", &n);
    
    char str[n][100];
    for (i = 0;i < n; ++i) gets(str[i]);

    
    int size, maxi,maxj, max = -1, maxcur, sum = 0;
    for(size = 0;size < n - 1 ;size++){
        for(i = 0;i < n;i++)
	    for(j = 0;j < n;j++)
	        if((i != j) && (str[i][0] != '*') &&  (str[j][0] != '*')){
		    maxcur = overlap(str[i], str[j]);
		    if(max < maxcur){
		        max = maxcur;
			maxi = i;
			maxj = j;
		    }
		}
		
         concat(str[maxi], str[maxj], max);	
	 max = -1;

    }

int len = strlen(str[maxi]);
printf("%d ", len);
}
    
    