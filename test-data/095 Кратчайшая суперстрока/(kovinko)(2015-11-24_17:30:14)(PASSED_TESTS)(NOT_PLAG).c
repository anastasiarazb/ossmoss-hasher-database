#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cross(char* s1, char* s2){
        int i,j,z,res;
	res=-100;
	if (s2[0]>0){
		for(i=0;s1[i]>0;i++){
			z=0;
			j=i;
			while(s1[j]>0 && s2[z]>0 && s1[j]==s2[z]){
				j++;
				z++;
			}
			if(s1[j]>0 && s2[z]>0){
				z=0;
			}
			if(z>res){
				res=z;
			}
		}
	}
	return res;
}

void concat(char* s1, char* s2){
	s1[strlen(s1)-cross(s1,s2)]='\0';
	strcat(s1,s2);
	s2[0]='\0';
}

int main()
{
	int n;
	scanf("%d\n", &n);
	char** arr=(char**)malloc(sizeof(char*)*n);
	int i,j,z,ind1,ind2,m;
	for(i=0;i<n;i++){
		arr[i]=(char*)malloc(sizeof(char)*1000);
		gets(arr[i]);
	}
	for(i=0;i<=n;i++){
		ind1=ind2=0;
		m=-100;
		for(j=0;j<n;j++){
			for (z=0;z<n;z++){
				if(j!=z && cross(arr[j],arr[z])>m){
					m=cross(arr[j],arr[z]);
					ind1=j;
					ind2=z;
				}
			}
		}
		if(ind1!=ind2){
			concat(arr[ind1],arr[ind2]);
		}
	}
	for(i=0;i<n;i++){
		if(strlen(arr[i])>0){
			printf("%d\n", strlen(arr[i]));
		}
	}
	for(i=0;i<n;i++){
		free(arr[i]);
	}
	free(arr);
	return(0);
}