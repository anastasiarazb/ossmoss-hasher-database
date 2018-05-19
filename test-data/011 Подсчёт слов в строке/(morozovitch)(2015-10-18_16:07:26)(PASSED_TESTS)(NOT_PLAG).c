#include <stdio.h>
#include <string.h>
#define MAX_LEN 10000
int wcount (char *s);

int main () {
char str_arr[MAX_LEN];
int am;

gets (str_arr);
am = wcount (str_arr);
printf ("%d\n", am);
return 0;
}

int wcount (char *s) {
int counter=0;
int status=0;
char *car_ptr;

for (car_ptr=s; *car_ptr!=0; car_ptr++) {
  if (status==0) {
    if (*car_ptr!=' ') {
      status=1;
      ++counter;
      } 
    }
  if (status==1) {
    if (*car_ptr==' ') {
      status=0;
      }      
    }
  }
return (counter);
}