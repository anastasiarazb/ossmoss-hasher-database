#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *concat(char (*s)[100], int n) 
{ 
    int i, len = 0;
   
    for (i = 0;i < n;i++)
        len += strlen(s[i]);
     
    char *l = calloc(len+1,sizeof(char));
    
     
    for (i = 0;i < n;i++){ 
        strncat(l, s[i], 100);    
    }
    return l;
}

int overlap(char *str1, char *str2)
{
    int j = 0,i = 0,len1 = strlen(str1), str2len = strlen(str2), over = 0;
    
    
    while((i < len1) && (j < str2len)){
        if(str1[i] == str2[j]){ 
            ++over; 
	    ++i; 
	    ++j;
	}else if(str1[i] == str2[0]){
	          over = 1;
	          ++i;
	      }else{
		  over = 0;
	          j = 0;
	          ++i;
	      }
     } 
     return over;
}


int main()
{
    int n, i, j;
    scanf("%d ", &n);
    
    char str[n][100];
    for (i = 0;i < n; ++i) gets(str[i]);
    
    
    int overlaps[n][n];
    for(i = 0;i < n;i++)
        for(j = 0;j < n;j++) 
	  if( i == j)  overlaps[i][j] = 0;
	  else  overlaps[i][j] = overlap(str[i], str[j]);
	
  
   int sum = 0, max, maxcur;
   for(i = 0;i < n;i++) {max = overlaps[i][i];
        for(j = i;j < n;j++){
	   if (overlaps[i][j] < overlaps[j][i]) maxcur = overlaps[j][i];
	   else maxcur = overlaps[i][j];
	   
	   if (max < maxcur) max = maxcur;
	}
	sum += max;
    }
    int len;
    char *con = concat(str, n);
    len = strlen(con);
    max = len - sum;
    printf("%d", max);
    free(con);
}
     
    