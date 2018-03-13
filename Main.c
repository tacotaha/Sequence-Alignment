#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Alignment.h"

/*Change this value to be roughly proprtional 
  to the square root of the amount of available
  Memory (in bytes)...*/
#define BUFFER 100000

int main(int argc, char** argv){
  char a[BUFFER], b[BUFFER], a_[BUFFER+1], b_[BUFFER+1],c;
  int z = 0;
  
  const int verbose = argc > 1 && strcmp(argv[1],"-v") == 0 ? 1 : 0;
  
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

  if(verbose){
    printf("Calculating Alignment...\n");
    //print_matrix(a_len,b_len,matrix);
  }
  
  alignment(a,b,a_,b_,matrix);
  
  print_alignment(a_,b_);

  if(verbose){
    end = clock();
    elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Elapsed Time: %fms\n",elapsed_time);
    printf("Edit Distance between strings: %d\n",edit_distance(matrix));
  }
  
  free(matrix);
  
  return 0;
}
