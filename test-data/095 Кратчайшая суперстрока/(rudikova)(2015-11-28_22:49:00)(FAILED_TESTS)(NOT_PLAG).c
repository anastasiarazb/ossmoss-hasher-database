#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int overlap(char *str1, char *str2)
{
    int j, i, len1 = strlen(str1), len2 = strlen(str2), over = 0, eq = 0;
    
    for(i = 1;i < len1;i++){
        j = i; 
        while((i < len1) && (j < len2)){
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
    strncat(str1, str2, 100);
    str2[0] = '*';
}

int main()
{
    int n, i, j;
    scanf("%d ", &n);
    
    char str[n][100];
    for (i = 0;i < n; ++i) gets(str[i]);

    
    int size, maxi,maxj, max, maxcur, sum = 0;
    for(size = 0;size < n;size++){
        for(i = 0;i < n;i++)
	    for(j = 0;i < n;j++)
	        if((i != j) && (str[i][0] != '*') &&  (str[j][0] != '*')){
		    maxcur = overlap(str[i], str[j]);
		    if(max < maxcur){
		        max = maxcur;
			maxi = i;
			maxj = j;
		    }
		}
		
         concat(str[maxi], str[maxj], max);		
    }

int len = strlen(str[maxi];
printf("%d ", len);
}
    