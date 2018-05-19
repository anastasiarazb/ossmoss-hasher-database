#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Record {
  int left_index, right_index, similar;
};

#define record struct Record

void sort(record arr[], unsigned begin, unsigned end) {
  record buf;
  unsigned i, counter;
  do {
    counter = 0;
    for (i = begin; i < end-1; i++) {
      if (arr[i].similar < arr[i+1].similar) {
        buf = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = buf;
        counter++;
      }
    }
  } while(counter > 0);
}

void exclude(record arr[], int idx, int idx2, unsigned n) {
  unsigned i = 0;
  for (i = 0; i < n; i++)
    if(arr[i].left_index == idx)
      arr[i].similar = -1;
    else if(arr[i].right_index == idx2)
      arr[i].similar = -1;
}

unsigned sim(char* s1, char* s2) {
  unsigned i, j, len1, len2, found, biggest = 0;
  len1 = strlen(s1);
  len2 = strlen(s2);
  for (i = 1; i <= len1 && i <= len2; i++) {
    found = 0;
    for (j = 0; j < i && !found; j++) {
      if(s1[len1-i+j] != s2[j])
        found = 1;
    }
    if(!found && i>biggest)
      biggest = i;
  }
  //if (found) i--;
  return biggest;
}

unsigned total_count(char **strings, unsigned n) {
  unsigned counter = 0, i;
  for(i = 0; i<n; i++)
    counter += strlen(strings[i]);
  return counter;
}

unsigned count(char **strings, unsigned n) {
  unsigned i, j, lessen_counter = 0;
  char helper;
  record mas[90];
  char found = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i != j) {
        helper = ((j>i)?j-1:j);
        mas[i*(n-1)+helper].left_index = i;
        mas[i*(n-1)+helper].right_index = j;
        mas[i*(n-1)+helper].similar = sim(strings[i], strings[j]);
      }
    }
  }
  for (i = 0; i < n-1 && !found; i++) {
    sort(mas, 0, n*(n-1));
    lessen_counter += mas[0].similar;
    exclude(mas, mas[0].left_index, mas[0].right_index, n*(n-1));
    if (mas[0].similar == 0)
     found = 1;
  }
  return total_count(strings, n)-lessen_counter;
}

int main(void) {
  char **strings;
  unsigned n, i;
  scanf("%u", &n);
  strings = (char**) malloc(n*sizeof(char*));
  for (i = 0; i < n; i++) {
    strings[i] = (char*) malloc(128);
    scanf("%s", strings[i]);
  }
  printf("%u", count(strings, n));
  for (i = 0; i < n; i++)
    free(strings[i]);
  free(strings);
  return 0;
}
