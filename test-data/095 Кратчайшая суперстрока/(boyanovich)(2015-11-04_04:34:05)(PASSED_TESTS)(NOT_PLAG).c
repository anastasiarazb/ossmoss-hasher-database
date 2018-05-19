#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1000

//returns the length of the longest suffix of string <a> that also happens
//to be the prefix of string <b>
int overlap_length(char* a, char* b, int la, int lb){
  int i,j,res;
  if(la>lb) i=la-lb;
  else i=1;
  
  while(i<la){
    j=i;
    res=la-i;
    while((j<la)&&(*(a+j)==*(b+(j-i)))) j++;
    if(j==la) return res;
    i++;
  }
  return 0;
}

//reverses the subarray of a given array, 
//specified by its first and last element
void reverse(int* base, int f, int l){
  int i,t,len=l-f+1;
  for(i=0;i<len/2;i++){
    t=base[f+i];
    base[f+i]=base[f+(len-1-i)];
    base[f+(len-1-i)]=t;
  }
}

//decides if looping for permutations should proceed
//initially set to 1, annihilated by the procedure <next>
//upon encountering the biggest permutation 
//(with respect to lexicographical ordering)
static int proceed;

//takes an array, containing a permutation of a finite
//subset of natural numbers (including zero and greater)
//transforms argument into the next permutation
//with respect to lexicographical ordering
//if provided the biggest permutation possible,
//does nothing to the array and sets the stop flag
void next(int* base, int nel){
  int i=nel-2;
  while((i+1) && (base[i]>base[i+1])) i--;
  if(i<0){
    proceed=0;
    return;
  }
  int j=nel-1;
  while(base[j]<=base[i]) j--;
  int t;
  t=base[i];
  base[i]=base[j];
  base[j]=t;
  reverse(base,i+1,nel-1); 
}

int main(int argc, char **argv){

  int n;
  scanf("%d ", &n);
  //string array
  char **sa = (char**) malloc(n*(sizeof(char*)+MAXLEN*sizeof(char)));
  //array of lengths of respective strings
  int len [n];
  //overlap matrix
  int **om = (int**) malloc(n*(sizeof(int*)+n*sizeof(int)));
  //minimal length of the concatenation sum of all strings
  int minl=0;
        
  int i;
  //in this loop, <minl> is set to the worst case
  //when none of the strings overlap at all
  for(i=0;i<n;i++){
    *(sa+i)=(char*)(sa+n)+i*MAXLEN;
    *(om+i)=(int*)(om+n)+i*n;
    gets(sa[i]);
    minl += len[i]=strnlen(sa[i],MAXLEN);   
  }
  int j;
  int permut [n];
  
  //generating initial permutation
  for(i=0;i<n;i++) permut[i]=i;
  
  //generating overlap matrix
  for(i=0;i<n-1;i++){
    for(j=i+1;j<n;j++){
      om[i][j]=overlap_length(sa[i],sa[j],len[i],len[j]);
      om[j][i]=overlap_length(sa[j],sa[i],len[j],len[i]);
    }
  }
  int s;
  
  //setting the flag
  proceed=1;
  
  //going through all possible permutations 
  //(representing sequential overlap concatenations)
  //length of the resulting string is determined by
  //the sum of the lengths of two operands, minus the length of the
  //overlap between the first and the second operand
  //if the sum for a certain permutation starts exceeding the current value of
  //<minl>, summation is ended prematurely
  //if we find a summary length that is less than curent <minl>, we reset
  //<minl> to that value, until all permutations are exhausted and we have
  //computed the length of the shortest superstring
  while(proceed){

   s=len[permut[0]];
   
   for(i=1;i<n;i++){
      s += len[permut[i]]-om[permut[i-1]][permut[i]];
      if(s>minl) break;
   }
   if(s<minl) minl=s;
   next((int*)permut,n);
  }
  printf("%d\n",minl);
 
  free(sa);
  free(om);
  
  return 0;
}