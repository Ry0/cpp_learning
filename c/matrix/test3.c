#include <stdio.h>
#define M 3

void input_mat(int mat[M][M]){
  int i,j;

  for(i=0;i<M;i++) {
    for(j=0;j<M;j++) {
      printf("行列の第%d行、第%d列を入力\n", i+1, j+1);
      scanf("%4d", &mat[i][j]);
    }
    printf("\n");
  }
}


void sum(int a[M][M], int b[M][M], int sum[M][M]){
  int i,j;

  for(i=0; i<M; i++){
    for(j=0; j<M; j++){
      sum[i][j] = a[i][j] + b[i][j];
    }
  }

  printf("行列Aと行列Bの和(A+B=)\n");
  for(i=0;i<M;i++){
    for (j=0;j<M;j++){
      printf("%4d ", sum[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}


void sub(int a[M][M], int b[M][M], int sub[M][M]){
  int i,j;

  for(i=0; i<M; i++){
    for(j=0; j<M; j++){
      sub[i][j] = a[i][j] - b[i][j];
    }
  }

  printf("行列Aと行列Bの差(A-B=)\n");
  for(i=0;i<M;i++){
    for(j=0;j<M;j++){
      printf("%4d ", sub[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}


int main(void){
  int matrix_A[M][M];
  int matrix_B[M][M];
  int mat_sum[M][M];
  int mat_sub[M][M];
  int i,j;

  printf("2つの行列の和と差を求める\n");

  printf("行列Aを入力\n");
  input_mat(matrix_A);

  printf("行列A=\n");
  for(i=0;i<M;i++) {
    for(j=0;j<M;j++) {
      printf("%4d ", matrix_A[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  printf("行列Bを入力\n");
  input_mat(matrix_B);

  printf("行列B=\n");
  for(i=0;i<M;i++) {
    for(j=0;j<M;j++) {
      printf("%4d ", matrix_B[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  sum(matrix_A, matrix_B, mat_sum);

  sub(matrix_A, matrix_B, mat_sub);

  return 0;
}
