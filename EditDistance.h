#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H

/*Costs Per Possibility*/
#define  GAP  2
#define MISMATCH 1
#define MATCH 0
#define BUF 1024

/* Return i,j'th element of the matrix*/
int ind(int row, int col, int width);

/* Cost of aligning a and b*/
int penalty(char a, char b);

int min(int a, int b, int c);

/*Populates the matrix based on the two strings*/
void populate_matrix(char* a, char* b, int* matrix);

/*Back-traces the matrix and returns the alignment*/
void alignment(char* a, char* b, int* matrix);

void print_matrix(int n,int m,int* matrix);
  
#endif

