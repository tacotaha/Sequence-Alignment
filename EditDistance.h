#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H


/*Costs Per Possibility*/
const int gap = 2;
const int mismatch = 1;
const int match = 0;

/* Return i,j'th index of matrix*/
int index(int row, int col, int width);

/* Cost of aligning a and b*/
int penalty(char a, char b);

int min(int a, int b, int c);

/*Populates the matrix based on the two strings*/
int populate_matrix(char* a, char* b, int* matrix);

/*Back-traces the matrix and returns the alignment*/
int alignment(char* a, char* b);

void print_matrix(int* matrix);
  
#endif

