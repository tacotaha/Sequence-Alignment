#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "EditDistance.h"

#define BUF 1024

int main(int argc, char* argv[]){
  //char c[BUF], d[BUF];
  
  //fgets(c, sizeof(c), stdin);
  //fgets(d, sizeof(d), stdin);

  char* a = "AACAGTTACC";
  char* b = "TAAGGTCA";

  char *a_ = malloc(sizeof(char) * (strlen(a)+1));
  char* b_ = malloc(sizeof(char) * (strlen(b)+1));
  
  memcpy(a_,a,strlen(a));
  memcpy(b_,b,strlen(b));

  a_[strlen(a)] = '-';
  a_[strlen(a) + 1] = '\0';
  
  b_[strlen(b)] = '-';
  b_[strlen(b) + 1] = '\0';

  printf("%ld\n",strlen(a_));
  printf("%ld\n",strlen(b_));
  
  int* matrix = malloc(sizeof(int) * strlen(a_) * strlen(b_));
  
  populate_matrix(a_, b_, matrix);
  
  print_matrix(strlen(a_),strlen(b_),matrix);

  alignment(a_, b_, matrix);

  printf("%s\n",a_);
  printf("%s\n",b_);

  free(matrix);
  
  return 0;
}

