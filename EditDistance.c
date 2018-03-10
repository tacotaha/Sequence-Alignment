#include <stdio.h>
#include <string.h>
#include "EditDistance.h"

void populate_matrix(char* a, char* b, int* matrix){
  int a_size = strlen(a);
  int b_size = strlen(b);
  
  matrix[ind(a_size, b_size, b_size+1)] = 0;

  for(int i = a_size - 1; i > -1; --i)
    matrix[ind(i,b_size,b_size+1)] = matrix[ind(i+1,b_size,b_size+1)] + GAP;

  for(int i = b_size - 1; i > -1; --i)
    matrix[ind(a_size, i, b_size+1)] = matrix[ind(a_size, i + 1, b_size+1)] + GAP;

  for(int i  = a_size - 1; i > -1; --i)
    for(int j = b_size - 1; j > -1; --j)
      matrix[ind(i,j,b_size+1)] =
	min(matrix[ind(i+1, j+1, b_size+1)] + penalty(a[i],b[j]), matrix[ind(i+1, j, b_size+1)]+GAP, matrix[ind(i, j+1, b_size+1) + GAP]);
      
}


int penalty(char a, char b){
  return a == b ? MATCH : MISMATCH;
}

int min(int a, int b, int c){
  int m = a < b ? a : b;
  return c < m ? c : m;
}

int ind(int row, int col, int width){
  return row* width + col;
}

void print_matrix(int n, int m,int* matrix){
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j)
      printf("%d\t", matrix[ind(i,j,m)]);
    printf("\n");
  }
}
