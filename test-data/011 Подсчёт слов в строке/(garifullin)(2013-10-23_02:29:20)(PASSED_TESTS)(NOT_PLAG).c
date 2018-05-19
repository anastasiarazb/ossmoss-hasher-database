#include <stdio.h>
#include <string.h>
int wcount(char *s){
        if (strlen(s)==0)  
		printf("0\n");
	else{
	int num=0,i;
	for (i=0;i<strlen(s)-1;i++){ 
    		if ((s[i]==' ') && (s[i+1]!=' ')){  	
        		num++;
    		}
	}
	if (s[0]!=' '){ 
		num++; 
	}
		printf("%d\n", num); 
	}
}
void read(char *s){
	gets(s);
}
void main(){
	const int size = 255; 
	char s[size];     
	read(s);
	wcount(s);
}