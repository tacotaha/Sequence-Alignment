#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "EditDistance.h"
#define BUFFER 100000

int main(int argc, char* argv[]){
  char a[BUFFER], b[BUFFER], a_[BUFFER+1], b_[BUFFER+1],c;
  int z = 0;
  
  clock_t start, end;
  double elapsed_time;
  
  while((c = getchar()))
    if(c == 0xa || z == BUFFER - 1){
      a[z++] = '-';
      a[z] = 0x0;
      break;
    }else a[z++] = c;
  
  size_t a_len = z; z = 0;
  
  while((c = getchar()))
    if(c == EOF || c == 0xa || z == BUFFER - 1){
      b[z++] = '-';
      b[z] = 0x0;
      break;
    }else b[z++] = c;
  
  fseek(stdout,0,SEEK_END);
  
  size_t b_len = z;
  
  int* matrix = malloc(sizeof(int) * a_len * b_len);
  
  start = clock();
  
  populate_matrix(a,b,matrix);
  
  printf("Calculating Alignment...\n");
  //print_matrix(a_len,b_len,matrix);
  
  alignment(a,b,a_,b_,matrix);
  
  print_alignment(a_,b_);
  
  end = clock();
  elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC;
  
  printf("Elapsed Time: %fms\n",elapsed_time);
  printf("Edit Distance between strings: %d\n",edit_distance(matrix));
  
  free(matrix);
  
  return 0;
}
