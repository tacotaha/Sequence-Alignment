#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "EditDistance.h"

void populate_matrix(char* a, char* b, int* matrix){
  int a_size = strlen(a);
  int b_size = strlen(b);
  
  matrix[ind(a_size-1, b_size-1, b_size)] = 0;
  
  for(int i = a_size-2;i > -1;--i)
    matrix[ind(i,b_size-1,b_size)] = matrix[ind(i+1,b_size-1,b_size)] + GAP;
  
  for(int i = b_size-2;i > -1;--i)
    matrix[ind(a_size-1,i,b_size)] = matrix[ind(a_size-1,i+1,b_size)] + GAP;
  
  for(int i  = a_size-2; i > -1; --i)
    for(int j = b_size-2; j > -1; --j)
      matrix[ind(i,j,b_size)] =
	min(matrix[ind(i+1, j+1, b_size)] + penalty(a[i],b[j]),
	    matrix[ind(i+1, j, b_size)] + GAP, matrix[ind(i, j+1, b_size)] + GAP);
}

void alignment(char* a, char* b, char* a_, char* b_, int* matrix){
  size_t i = 0, j = 0, x = 0, y = 0, ai = 0, bi = 0;
  int m = matrix[ind(i,j,strlen(b))];
  
  while(i < strlen(a) - 1&& j < strlen(b) - 1){
    if(m == matrix[ind(x+1,y,strlen(b))] + GAP){
      a_[ai++] = a[i++];
      b_[bi++] = '-';
      ++x;
    }else if(m == matrix[ind(x,y+1,strlen(b))] + GAP){
      ++y;
      a_[ai++] = '-';
      b_[bi++] = b[j++];
    }else if(m == matrix[ind(x+1,y+1,strlen(b))] ||
	     m == matrix[ind(x+1, y+1,strlen(b))] + MISMATCH){
      ++x; ++y;
      a_[ai++] = a[i++];
      b_[bi++] = b[j++];
    }
    m = matrix[ind(x,y,strlen(b))];
  }
}

int penalty(char a, char b){
  return a == b ? MATCH : MISMATCH;
}

int min(int a, int b, int c){
  int m = a < b ? a : b;
  return c < m ? c : m;
}

int ind(int row, int col, int width){
  return row*width + col;
}

void print_matrix(int n, int m,int* matrix){
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j)
      printf("%d\t", matrix[ind(i,j,m)]);
    printf("\n");
  }
}
