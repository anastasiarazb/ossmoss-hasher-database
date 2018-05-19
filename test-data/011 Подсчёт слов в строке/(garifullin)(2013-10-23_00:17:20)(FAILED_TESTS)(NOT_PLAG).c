#include <stdio.h>
#include <string.h>
void wcount(char *str){
        int num=0,i;
	for (i=0;i<strlen(str)-1;i++){ 
    		if ((str[i]==' ') && (str[i+1]!=' ')){  	
        		num++;
    		}
	}
	if (str[0]!=' '){ 
		num++; 
	}
	printf("%d\n", num); 
}
void read(char *str){
	gets(str);
}
void main(){
	const int size = 255; 
	char str[size];     
	read(str);
	wcount(str);
}