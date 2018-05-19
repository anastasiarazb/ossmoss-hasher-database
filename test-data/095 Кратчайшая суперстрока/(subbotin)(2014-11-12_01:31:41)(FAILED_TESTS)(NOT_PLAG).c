#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Permut_rec(char **a, int n, int j, int *f) 
{
  if(j == n - 1) {
      int i,r=1,s,m;
      for(i=s=m=0;i<n-1;++i,r=1,s=0) {
        while(a[i][r]) {
	  if(a[i][r] == a[i+1][s]) {
	    ++s;
	    ++r;
	  } else {
	    r-=s;
	    ++r;
	    s=0;
	   
	      
	    }
	  
	} 
	m+=s;
      }
      
      if(f[1] - m+1 < f[0])  f[0] = f[1] - m;
  } else {
      int i;
      for(i = j; i < n; ++i) {
	char *p = a[i];
	a[i] = a[j];
	a[j] = p;
	Permut_rec(a, n, j+1, f);
	p = a[i];
	a[i] = a[j];
	a[j] = p;
      }
  }
}

int main(int argc, int **argv)
{
        int n, i, k,r,x,m=0;
        scanf("%d ", &n);
	char *a[n];
        /*char *a[n], b[n][500];*/
	/*for(i=0;i<n;++i) {
	  fgets(b[i], 500, stdin);
	  b[i][strnlen(b[i],500) - 1]=0;
	  a[i]=b[i];
	}*/
        char *s = (char*)malloc(100*n*sizeof(char));
        for(i = 0,k = 0,*a = s;i < n;++i) {
	  a[i] = fgets (s+(100*i), 100 , stdin);
	  a[i][strnlen(a[i],100) - 1]= 0;
	  k += strnlen(a[i], 100);
	}
int p[2];
p[1]=p[0]=k;
     printf("%d\n", k);
     /*for(i=x=m=0,r = 1;i<n-1;++i,x=0,r = 1) {
	while(a[i][r]) {
	  if(a[i][r] == a[i+1][x]) {
	    
	    ++x;
	    ++r;
	  } else {
	    r-=x;
	    x=0;
	    ++r;
	   
	}
	printf("%d %d ", r, x);
	  
	}
	m += x;
	  printf("%d,x ", x);
	printf("%d,m ", m);
      }*/
	Permut_rec(a, n, 0, p);
	printf("%d\n", p[0]);
	free(s);
	return 0;
	
}