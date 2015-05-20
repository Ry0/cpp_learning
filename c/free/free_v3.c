#include <stdio.h>
#include <stdlib.h>

#define FILTERSIZE 3

void InitMatrix(double **mat, int row, int column)
{
  int i, j, init = 0;
  for(i=0; i<row; i++){
    for(j=0; j<column; j++){
      mat[i][j] = init % 5;
      init++;
    }
  }
}

void PrintMatrix(double **mat, int row, int column)
{
  int i,j = 0;
  for(i=0; i<row; i++){
    printf("|");
    for(j=0; j<column; j++){
      printf("%6.2lf", mat[i][j]);
    }
    printf("|");
    printf("\n");
  }
}

int main(void)
{
  int i, j, l, m, init = 0;
  int start = 0;
  int row, column = 0;
  unsigned long int cnt = 0;
  double sum = 0;
  double **mat_a = 0;		/* original matrix */
  double **mat_b = 0;		/* filtered matrix */

  printf("何行何列にしますか？\n");
  printf("行："); scanf("%d",&row);
  printf("列："); scanf("%d",&column);

  /* Get of memory */
  mat_a = malloc(sizeof(double)*row);
  mat_b = malloc(sizeof(double)*row);
  for(i=0; i<row; i++){
    mat_a[i] = malloc(sizeof(double)*column);
    mat_b[i] = malloc(sizeof(double)*column);
  }

  /* Initialization Matrix */
  InitMatrix(mat_a, row, column);
  InitMatrix(mat_b, row, column);
  printf("\n");

  /* Print Original Matrix */
  printf("\nOriginal=\n");
  PrintMatrix(mat_a, row, column);

  /* Calc data */
  start = (int)FILTERSIZE/2;
  for(i=start, j=start; i<row-start; i++,j=start){
    for(l=i-start; l<FILTERSIZE+i-start; l++){
      for(m=j-start; m<FILTERSIZE+j-start; m++){
        sum += mat_a[l][m];
        cnt++;
      }
    }
    mat_b[i][j] = sum/(FILTERSIZE*FILTERSIZE);
    for(j=j+1; j<column-start-1;j++){
      for(l=i-start; l<FILTERSIZE+i-start; l++){
        sum += mat_a[l][j+start];
        cnt++;
        sum -= mat_a[l][j-start-1];
        cnt++;
      }
      mat_b[i][j] = sum/(FILTERSIZE*FILTERSIZE);
    }
    sum = 0;
  }

  /* Print result */
  printf("\nResult=\n");
  PrintMatrix(mat_b, row, column);

  printf("cnt == %ld\n",cnt);

  /* Free memory */
  for(i=0; i<row; i++){
      free(mat_a[i]);
      free(mat_b[i]);
  }
  free(mat_a);
  free(mat_b);

  return 0;
}
