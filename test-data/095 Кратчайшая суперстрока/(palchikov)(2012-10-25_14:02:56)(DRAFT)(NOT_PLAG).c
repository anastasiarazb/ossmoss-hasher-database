
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mut(char *a, char *b){
        int i, j, m, res=0, f=0;
        m = strlen(a);
        if(m>strlen(b)) m=strlen(b);//???
        for(i=strlen(a)-1;i>=0 && strlen(a)-i<=strlen(b);i--){
                f=1;
                for(j=0; j < strlen(b) && j < strlen(a)-i;j++){
                //printf("%c %c %d\n", a[i+j], b[j], res);
                    if(a[i+j]!= b[j]){
                        f=0; break;
                    }
                }  
                if(f==1) res = strlen(a)-i;    
                    

        }
        //printf("%s %s %d\n", a, b, res);
        return res;
}

int minLength(char** strs, char* str, int a[]){
        int i, t=0, t1, max=0;
        for(i=0;i<10;i++){
                if(a[i]==1){
                        a[i]=0; //printf("%s \n",strs[i]);
                        t = minLength(strs, strs[i], a);
        		a[i]=1;
                        t1 = mut(str, strs[i]);
                        if(t1+t > max) max = t1+t;
                        //printf("%d %d %s\n", t1, t, str);
                }
        }
        
        return max;      
        
}

int main()
{
        int n, i, min, res=0, sum = 0, a[10]={0};
        char **str;
        scanf("%d\n", &n);
        str = (char**)malloc(n*sizeof(char*));
        for(i=0;i<n;i++){
            str[i] = (char*)malloc(100);
            scanf("%s", str[i]);
            a[i]=1;
            sum+=strlen(str[i]);
        }
        res=sum;
        for(i=0;i<n;i++){
                a[i] = 0;
                min = minLength(str, str[i], a); //printf("%s %d %d\n",str[i], res, min);
                a[i]=1;
                if (res>sum-min) res = sum-min;
        }
        
        
        printf("%d\n", res);
        for(i=0;i<n;i++)
            free(str[i]);
        free(str);
        return 0;
}