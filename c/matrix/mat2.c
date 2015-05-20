#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int i, j = 0;
  int row, column = 0;
  double **mat_a = 0;
  double **mat_b = 0;

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
  /* Input Matrix data */
  for(i=0; i<row; i++){
    for(j=0; j<column; j++){
      printf("input Matrix A[%d][%d]:", i, j);
      scanf("%lf", &mat_a[i][j]);
    }
  }
  for(i=0; i<row; i++){
    for(j=0; j<column; j++){
      printf("input Matrix B[%d][%d]:", i, j);
      scanf("%lf", &mat_b[i][j]);
    }
  }
  /* calc data */
  for(i=0; i<row; i++){
    for(j=0; j<column; j++){
      mat_a[i][j] = mat_a[i][j] + mat_b[i][j];
      mat_b[i][j] = mat_a[i][j] - 2*mat_b[i][j];
    }
  }
  /* print data */
  printf("\nA+B\n");
  for(i=0; i<row; i++){
    printf("|");
    for(j=0; j<column; j++){
      printf("%6.2f", mat_a[i][j]);
    }
    printf("|");
    printf("\n");
  }
  printf("\nA-B\n");
  for(i=0; i<row; i++){
    printf("|");
    for(j=0; j<column; j++){
      printf("%6.2f", mat_b[i][j]);
    }
    printf("|");
    printf("\n");
  }
  /* Free memory */
  for(i=0; i<row; i++){
    free(mat_a[i]);
    free(mat_b[i]);
  }
  free(mat_a);
  free(mat_b);
  return 0;
}
