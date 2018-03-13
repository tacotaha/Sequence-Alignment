#ifndef ALIGNMENT_H
#define ALIGNMENT_H

/*Costs Per Possibility*/
#define GAP      2
#define MISMATCH 1
#define MATCH    0

/*Return i,j'th element of the matrix*/
int ind(int row,int col,int width);

/*Cost of aligning a and b*/
int penalty(char a,char b);

/*Populates the matrix based on the two strings*/
void populate_matrix(char* a,char* b,int* matrix);

/*Back-traces the matrix and returns the alignment*/
void alignment(char* a,char* b,char* a_aligned,char* b_aligned,int* matrix);

/*Print strings aligned vertically*/
void print_alignment(char* a,char* b);

/*Precondition: populate_matrix() must be called prior to this...
  Returns: the edit distance between the two strings represented
  by the matrix*/
int edit_distance(int* matrix);

int min(int a,int b,int c);

void print_matrix(int n,int m,int* matrix);
#endif
