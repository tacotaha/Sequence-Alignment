#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "EditDistance.h"

#define BUF 1024

int main(int argc, char* argv[]){
  //char c[BUF], d[BUF];
  
  //fgets(c, sizeof(c), stdin);
  //fgets(d, sizeof(d), stdin);
  
  char* a = "AACAGTTACC-";
  char* b = "TAAGGTCA-";

  int* matrix = malloc(sizeof(int) * strlen(a) * strlen(b));
  
  populate_matrix(a, b, matrix);
  
  print_matrix(strlen(a),strlen(b),matrix);
  
  free(matrix);
  
  return 0;
}
