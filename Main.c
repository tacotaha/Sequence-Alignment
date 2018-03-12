#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "EditDistance.h"
#define BUFFER 2048

int main(int argc, char* argv[]){
  char a[BUF], b[BUF];
  
  fgets(a, sizeof(a), stdin);
  fgets(b, sizeof(b), stdin);

  int larger = strlen(a) > strlen(b) ? strlen(a) : strlen(b);
  
  char *a_ = malloc(sizeof(char) * larger+1);
  char* b_ = malloc(sizeof(char) * larger+1);
  
  int* matrix = malloc(sizeof(int) * strlen(a) * strlen(b));
  
  populate_matrix(a, b, matrix);
  
  print_matrix(strlen(a),strlen(b),matrix);
  
  alignment(a,b,a_, b_, matrix);
  
  printf("%s\n",a_);
  printf("%s\n",b_);
  
  free(matrix);
  free(a_);
  free(b_);
  
  return 0;
}

